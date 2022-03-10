/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 20:18:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "ftprintf.h"
#include "parser/parser.h"

void	command_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s\n",
		"minishell",
		strerror(errno));
}

void	command_file_error_errcode(t_command *command, int errcode)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		strerror(errcode));
}

void	command_file_error_message(t_command *command, char *message)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		message);
}

void	command_not_found_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		"command not found");
}

void	build_argv_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	perror("minishell");
}
