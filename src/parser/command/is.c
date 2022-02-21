/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 00:33:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

int	command_is_empty(t_command *command)
{
	return (
		command == NULL
		|| (command->type == COMMAND_SIMPLE
			&& command->data.simple.args.size == 0
			&& command->data.simple.redirections.size == 0)
	);
}

int	command_is(t_command *command, t_command_type type)
{
	return (command->type == type);
}
