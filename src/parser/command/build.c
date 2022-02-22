/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:42:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static int	build_stop(t_parser *parser, t_iter *iter, t_command **command)
{
	if (parser->status != PARSER_STATUS_DEFAULT || !iter_next(iter))
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

static void	handle_redirection(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	command_redirection_build(parser, iter,
		command_get_redirections(*command));
	command_build(parser, iter, command);
}

static void	handle_compound(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	command_compound_build(parser, iter, command);
	command_build(parser, iter, command);
}

void	command_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	if (build_stop(parser, iter, command))
		return ;
	token = (t_token *)iter->data;
	if (token_is_redirection_operator(token))
		handle_redirection(parser, iter, command);
	else if (token_is(token, TOK_O_PARENTHESIS))
		handle_compound(parser, iter, command);
	else if (token_is(token, TOK_AND_IF) || token_is(token, TOK_OR_IF))
		command_list_build(parser, iter, command);
	else if (token_is(token, TOK_PIPE))
		command_pipeline_build(parser, iter, command);
	else if (!lst_push_back(command_get_args(*command), token))
		parser_internal_error(parser);
	else
		command_build(parser, iter, command);
}
