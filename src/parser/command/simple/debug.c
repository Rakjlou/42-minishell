/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:36:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_simple_debug(t_command *command)
{
	t_iter			iter;
	t_token			*token;
	t_redirection	*redirection;

	iter_init(&iter, &command->data.simple.args, ASC);
	if (command_is_empty(command))
		return ((void)ftprintf("\n"));
	ftprintf("- ");
	while (iter_next(&iter))
	{
		token = (t_token *)iter.data;
		ftprintf("%s ", token->raw);
	}
	iter_init(&iter, &command->data.simple.redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = (t_redirection *)iter.data;
		ftprintf("%s %s ", redirection->type->raw, redirection->arg->raw);
	}
	ftprintf("\n");
}
