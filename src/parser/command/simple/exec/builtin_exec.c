/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 20:25:42 by nsierra-         ###   ########.fr       */
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

void	builtin_exec(t_command *command)
{
	if (!ft_strncmp(command->argv[0], "echo", -1))
		command->status = bi_echo(command->argv);
	else if (!ft_strncmp(command->argv[0], "cd", -1))
		command->status = bi_cd(command->argv);
	else if (!ft_strncmp(command->argv[0], "pwd", -1))
		command->status = bi_pwd(command->argv);
	else if (!ft_strncmp(command->argv[0], "export", -1))
		command->status = bi_export(command->argv);
	else if (!ft_strncmp(command->argv[0], "unset", -1))
		command->status = bi_unset(command->argv);
	else if (!ft_strncmp(command->argv[0], "env", -1))
		command->status = bi_env(command->argv);
	else if (!ft_strncmp(command->argv[0], "exit", -1))
		command->status = bi_exit(command->argv);
}
