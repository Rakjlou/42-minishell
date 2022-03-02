/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:38:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		(void)redirection;
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
		(void)arg;
	}
	return (1);
}

void	command_simple_run(t_command *command)
{
	t_command_simple	*simple_data;

	simple_data = &command->data.simple;
	command_simple_handle_redirections(command);
	command_simple_exec(command);
	(void)simple_data;
}
