/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:26:42 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:48:09 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

static int	command_simple_handle_redirections(t_command *command)
{
	t_lst			*redirections;
	t_redirection	*redirection;
	t_iter			iter;

	redirections = &command->data.simple.redirections;
	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		ftfprintf(
			STDERR_FILENO,
			"\tRedirection %s %s >",
			redirection->type->raw,
			redirection->arg->raw
		);
		ftfprintf(STDERR_FILENO, "<\n");
		print_wordexp(redirection->arg);
	}
	return (1);
}

static int	command_simple_exec(t_command *command)
{
	t_lst			*args;
	t_iter			iter;
	t_token			*arg;

	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		ftfprintf(STDERR_FILENO, "\tArg %s >", arg->raw);
		print_wordexp(arg);
		ftfprintf(STDERR_FILENO, "<\n");
	}
	return (1);
}

void	command_simple_run(t_command *command)
{
	ftfprintf(STDERR_FILENO, "----   Simple Command   ----\n");
	command_simple_handle_redirections(command);
	command_simple_exec(command);
	ftfprintf(STDERR_FILENO, "---- End Simple Command ----\n");

}
