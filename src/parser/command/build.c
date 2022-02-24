/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/24 19:36:44 by nsierra-         ###   ########.fr       */
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

	if (parser->status != PARSER_STATUS_DEFAULT || !iter_next(iter))
		return ;
	token = (t_token *)iter->data;
	if (command_is_start_of(token, COMMAND_COMPOUND))
		command_compound_build(parser, iter, command);
	else if (command_is_start_of(token, COMMAND_LIST))
		command_list_build(parser, iter, command);
	else if (command_is_start_of(token, COMMAND_PIPELINE))
		command_pipeline_build(parser, iter, command);
	else if (command_is_start_of(token, COMMAND_SIMPLE))
		command_simple_build(parser, iter, command);
	else
		parser_unexpected_token(parser, token);
}
