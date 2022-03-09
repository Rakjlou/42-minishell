/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:12:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

static void	command_simple_exec(t_command *command)
{
	t_lst			*args;
	t_iter			iter;
	t_token			*arg;
	int				i;

	if (command->status != 0)
		return ;
	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		arg->expanded = wordexp(arg->raw);
		i = 0;
		while (arg->expanded && arg->expanded[i])
			ftprintf("%s\n", arg->expanded[i++]);
	}
	return ;
}

void	command_simple_run(t_command *command)
{
	redirections_run(command, &command->data.simple.redirections);
	command_simple_exec(command);
	redirections_stop(&command->data.simple.redirections);
}
