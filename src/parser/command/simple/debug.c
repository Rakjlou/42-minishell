/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 21:08:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_simple_debug(t_command *command)
{
	t_iter			iter;
	t_token			*token;

	iter_init(&iter, &command->data.simple.args, ASC);
	if (command_is_empty(command))
		return ((void)ftprintf("\n"));
	ftprintf("- ");
	while (iter_next(&iter))
	{
		token = (t_token *)iter.data;
		ftprintf("%s ", token->raw);
	}
	redirections_debug(&command->data.simple.redirections);
	ftprintf("\n");
}
