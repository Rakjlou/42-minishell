/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/22 21:13:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"

static int	handle_pipe(t_command *command)
{
	int	fds[2];

	if (!_shell()->exec.pipeline)
		return (1);
	fds[0] = command->parent->data.pipeline.fds[0];
	fds[1] = command->parent->data.pipeline.fds[1];
	if (_shell()->exec.pipeline == 1)
	{
		ftprintf("_shell()->exec.pipeline == 1\n");
		dup2(fds[PIPE_WRITE], _shell()->exec.pipe_out);
		close(fds[PIPE_READ]);
		return (1);
	}
	else if (_shell()->exec.pipeline == 2)
	{
		ftprintf("_shell()->exec.pipeline == 2\n");
		dup2(fds[PIPE_READ], _shell()->exec.pipe_in);
		close(fds[PIPE_READ]);
	}
	return (1);
}

static void	command_exec_child(t_command *command, char *path)
{
	if (handle_pipe(command)
		&& redirections_run(command, &command->data.simple.redirections)
		&& execve(path, command->argv, _shell()->param.env) == -1)
	{
		redirections_stop(&command->data.simple.redirections);
		command_error(command);
	}
}

static int	process_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static void	parent_wait_pipeline(t_command *command, pid_t child_pid)
{
	(void)command;
	(void)child_pid;
	_shell()->exec.pipeline++;
}

static void	parent_wait(t_command *command, pid_t child_pid)
{
	int	status;

	if (_shell()->exec.pipeline > 0)
		parent_wait_pipeline(command, child_pid);
	if (waitpid(child_pid, &status, 0) == -1)
		return (command_error(command));
	command_set_last_status(command, process_exit_status(status));
	if (!WIFSTOPPED(status) && WIFSIGNALED(status))
	{
		if (WTERMSIG(status) != SIGINT && WTERMSIG(status) != SIGTERM)
		{
			ftfprintf(STDERR_FILENO, "%s", sigstr(WTERMSIG(status)));
			if (WCOREDUMP(status))
				ftfprintf(STDERR_FILENO, " (core dumped)");
			ftfprintf(STDERR_FILENO, "\n");
		}
	}
}

void	command_exec(t_command *command)
{
	char	*path;
	pid_t	child_pid;

	if (command->status != EXIT_SUCCESS || !command_find_path(command, &path))
		return ;
	child_pid = fork();
	if (child_pid == -1)
		return (command_error(command));
	else if (child_pid == 0)
		command_exec_child(command, path);
	else
		(free(path), parent_wait(command, child_pid));
}
