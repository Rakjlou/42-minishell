/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/04 20:40:49 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

static void	command_simple_handle_redirections(t_command *command)
{
	t_lst			*redirections;
	t_redirection	*redirection;
	t_iter			iter;

	redirections = &command->data.simple.redirections;
	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		redirection->arg->expanded = wordexp(redirection->arg->raw);
		if (ft_cmatrix_size(redirection->arg->expanded) > 1
			|| ft_cmatrix_size(redirection->arg->expanded) == 0)
		{
			command->status = 1;
			ftfprintf(
				STDERR_FILENO,
				"%s: %s: ambiguous redirect\n",
				"minishell",
				redirection->arg->raw);
		}
		(void)redirection;
	}
	return ;
}

static void	command_simple_exec(t_command *command)
{
	t_lst			*args;
	t_iter			iter;
	t_token			*arg;

	if (command->status != 0)
		return ;
	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		arg->expanded = wordexp(arg->raw);
		(void)arg;
	}
	return ;
}

void	command_simple_run(t_command *command)
{
	command_simple_handle_redirections(command);
	command_simple_exec(command);
}
