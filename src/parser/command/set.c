/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 23:52:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"

void	command_set_last(t_command *command)
{
	t_shell	*shell;

	shell = _shell();
	shell->last_command = command;
	shell->last_command_status = command->status;
}

void	command_set_last_status(t_command *command, int status)
{
	command->status = status;
	if (DEBUG_COMMAND_STATUS)
		ftfprintf(STDERR_FILENO, "status %d\n", status);
	command_set_last(command);
}
