/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 19:28:31 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"
#include "handle_signal.h"

static int	handle_pipe(t_command *command)
{
	int	current_fd[2];

	if (!pipeline_is_active())
		return (1);
	current_fd[PIPE_WRITE] = command->parent->data.pipeline.fds[PIPE_WRITE];
	current_fd[PIPE_READ] = command->parent->data.pipeline.fds[PIPE_READ];
	if (pipeline_is_first())
	{
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(current_fd[PIPE_READ]);
		return (1);
	}
	else if (pipeline_is_middle())
	{
		dup2(command->parent->parent->data.pipeline.fds[PIPE_READ], _shell()->pipeline.pipe_in);
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(command->parent->parent->data.pipeline.fds[PIPE_READ]);
		close(command->parent->data.pipeline.fds[PIPE_READ]);
	}
	else if (pipeline_is_last())
	{
		dup2(current_fd[PIPE_READ], _shell()->pipeline.pipe_in);
		close(current_fd[PIPE_WRITE]);
	}
	return (1);
}

static void	command_exec_child(t_command *command, char *path)
{
	handle_signals(CHILD);
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
	(void)child_pid;
	if (pipeline_is_first())
	{
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
	}
	else if (pipeline_is_last())
	{
		close(command->parent->data.pipeline.fds[PIPE_READ]);
		_shell()->pipeline.r--;
		pipeline_close();
	}
	else if (pipeline_is_middle())
	{
		close(command->parent->parent->data.pipeline.fds[PIPE_READ]);
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
		_shell()->pipeline.r--;
	}
}

static void	parent_wait(t_command *command, pid_t child_pid)
{
	int	status;

	handle_signals(PARENT);
	if (pipeline_is_active())
	{
		parent_wait_pipeline(command, child_pid);
		handle_signals(MAIN_PROCESS);
		return ;
	}
	else if (waitpid(child_pid, &status, 0) == -1)
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
	handle_signals(MAIN_PROCESS);
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
