/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 23:07:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"

static void	command_exec_child(t_command *command, char *path)
{
	if (execve(path, command->argv, _shell()->param.env) == -1)
	{
		command_error(command);
		shell_destroy();
		exit(EXIT_FAILURE);
	}
}

static int	process_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

static void	parent_wait(t_command *command, pid_t child_pid)
{
	int	status;

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
