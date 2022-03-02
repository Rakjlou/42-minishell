/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/24 19:38:20 by nsierra-         ###   ########.fr       */
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

int	command_is_start_of(t_token *token, t_command_type type)
{
	if (type == COMMAND_PIPELINE)
		return (token_is(token, TOK_PIPE));
	else if (type == COMMAND_LIST)
		return (token_is(token, TOK_AND_IF) || token_is(token, TOK_OR_IF));
	else if (type == COMMAND_COMPOUND)
		return (token_is(token, TOK_O_PARENTHESIS));
	else if (type == COMMAND_SIMPLE)
	{
		return (token_is_redirection_operator(token)
			|| token_is(token, TOK_TOKEN));
	}
	return (0);
}
