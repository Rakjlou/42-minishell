/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 02:42:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#include "parser/parser.h"

static void	consume_redirection(t_parser *parser, t_iter *iter, t_command **cmd)
{
	t_redirection	candidate;
	t_redirection	*redirection;

	candidate.type = (t_token *)iter->data;
	if (!iter_next(iter))
		return (parser_unexpected_token(parser, NULL));
	candidate.arg = (t_token *)iter->data;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
		return (parser_internal_error(parser));
	redirection = ft_memcpy(redirection, &candidate, sizeof(t_redirection));
	if (!lst_push_back(command_get_redirections(*cmd), redirection))
		parser_internal_error(parser);
}

static int	must_stop(t_parser *parser, t_iter *iter, t_command **command)
{
	if (!iter_next(iter))
		return (1);
	else if (token_is((t_token *)iter->data, TOK_C_PARENTHESIS))
	{
		if (parser->subshell <= 0)
			parser_unexpected_token(parser, (t_token *)iter->data);
		else if (command_is_empty(*command))
		{
			--parser->subshell;
			parser_unexpected_token(parser, (t_token *)iter->data);
		}
		else
			--parser->subshell;
		return (1);
	}
	return (0);
}

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

void	command_simple_consume(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	if (must_stop(parser, iter, command))
		return ;
	token = (t_token *)iter->data;
	if (token_is_redirection_operator(token))
	{
		consume_redirection(parser, iter, command);
		command_simple_consume(parser, iter, command);
	}
	else if (token_is(token, TOK_O_PARENTHESIS))
	{
		command_compound_consume(parser, iter, command);
		command_simple_consume(parser, iter, command);
	}
	else if (token_is(token, TOK_AND_IF) || token_is(token, TOK_OR_IF))
		command_list_consume(parser, iter, command);
	else if (token_is(token, TOK_PIPE))
		command_pipeline_consume(parser, iter, command);
	else if (!lst_push_back(command_get_args(*command), token))
		parser_internal_error(parser);
	else
		command_simple_consume(parser, iter, command);
}
