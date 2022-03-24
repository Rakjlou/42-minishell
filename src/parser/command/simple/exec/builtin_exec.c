/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 14:19:02 by nsierra-         ###   ########.fr       */
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

static void	builtin_exec_real(t_command *command)
{
	if (!pipeline_handle(command))
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
		pipeline_fork_parent(command);
}

void	builtin_exec(t_command *command)
{
	if (pipeline_is_active())
		return (builtin_exec_pipeline(command));
	return (builtin_exec_real(command));
}
