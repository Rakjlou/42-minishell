/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 21:11:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftprintf.h"
#include "wordexp.h"
#include "env.h"
#include "shell.h"
#include "built_in.h"
#include "parser/parser.h"

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

static void	builtin_exec_real(t_command *command)
{
	if (!handle_pipe(command))
		return (command_error(command));
	else if (!redirections_run(command, &command->data.simple.redirections))
		return (redirections_stop(&command->data.simple.redirections));
	else if (!ft_strncmp(command->argv[0], "echo", -1))
		command_set_last_status(command, bi_echo(command->argv));
	else if (!ft_strncmp(command->argv[0], "cd", -1))
		command_set_last_status(command, bi_cd(command->argv));
	else if (!ft_strncmp(command->argv[0], "pwd", -1))
		command_set_last_status(command, bi_pwd(command->argv));
	else if (!ft_strncmp(command->argv[0], "export", -1))
		command_set_last_status(command, bi_export(command->argv));
	else if (!ft_strncmp(command->argv[0], "unset", -1))
		command_set_last_status(command, bi_unset(command->argv));
	else if (!ft_strncmp(command->argv[0], "env", -1))
		command_set_last_status(command, bi_env(command->argv));
	else if (!ft_strncmp(command->argv[0], "exit", -1))
		command_set_last_status(command, bi_exit(command->argv));
	redirections_stop(&command->data.simple.redirections);
}

static void	builtin_exec_pipeline(t_command *command)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork();
	if (child_pid == -1)
		return (command_error(command));
	else if (child_pid == 0)
	{
		builtin_exec_real(command);
		status = command->status;
		shell_destroy();
		exit(status);
	}
	else
		parent_wait_pipeline(command, child_pid);
}

void	builtin_exec(t_command *command)
{
	if (pipeline_is_active())
		return (builtin_exec_pipeline(command));
	return (builtin_exec_real(command));
}
