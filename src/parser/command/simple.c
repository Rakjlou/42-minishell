/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 20:25:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

static void	consume_redirection(t_parser *parser, t_iter *iter, t_command **cmd)
{
	t_redirection	candidate;
	t_redirection	*redirection;

	candidate.type = (t_token *)iter->data;
	if (!iter_next(iter))
	{
		parser_unexpected_token(parser, NULL);
		return ;
	}
	candidate.arg = (t_token *)iter->data;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
	{
		parser_internal_error(parser);
		return ;
	}
	redirection = ft_memcpy(redirection, &candidate, sizeof(t_redirection));
	if (!lst_push_back(command_get_redirections(*cmd), redirection))
		parser_internal_error(parser);
}

void	command_simple_debug(t_command *command)
{
	t_iter			iter;
	t_token			*token;
	t_redirection	*redirection;

	iter_init(&iter, &command->data.simple.args, ASC);
	if (command_is_empty(command))
		ftprintf("(empty)");
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

t_lst	*command_get_redirections(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		return (&command->data.simple.redirections);
	return (NULL);
}

t_lst	*command_get_args(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		return (&command->data.simple.args);
	return (NULL);
}

void	command_simple_consume(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	if (!iter_next(iter))
		return ;
	token = (t_token *)iter->data;
	if (token_is_redirection_operator(token))
	{
		consume_redirection(parser, iter, command);
		command_simple_consume(parser, iter, command);
	}
	else if (token_is_logical_operator(token))
		command_list_consume(parser, iter, command);
	else if (token_is_pipeline(token))
		command_list_consume(parser, iter, command);
	else if (!lst_push_back(command_get_args(*command), token))
		parser_internal_error(parser);
	else
		command_simple_consume(parser, iter, command);
}
