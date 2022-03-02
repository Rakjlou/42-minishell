/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 01:24:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

static int	valid_start(t_token *token)
{
	return (
		token_is_redirection_operator(token)
		|| token_is(token, TOK_TOKEN)
	);
}

static void	command_simple_build_recursive(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;
	t_command	*cmd;

	token = iter->data;
	cmd = *command;
	if (parser->status != PARSER_STATUS_DEFAULT || !valid_start(token))
		return ;
	else if (token_is_redirection_operator(token))
	{
		command_redirection_build(
			parser,
			iter,
			&cmd->data.simple.redirections);
	}
	else if (!lst_push_back(&cmd->data.simple.args, token))
		return (parser_internal_error(parser));
	else
	{
		token->type = TOK_WORD;
		parser_next_token(parser, iter);
	}
	command_simple_build_recursive(parser, iter, command);
}

void	command_simple_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	token = iter->data;
	if (!valid_start(token))
		return (parser_unexpected_token(parser, token));
	return (command_simple_build_recursive(parser, iter, command));
}
