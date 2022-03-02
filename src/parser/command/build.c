/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 02:00:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static void	command_build_loop(
	void (*callback)(t_parser *, t_iter *, t_command **),
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	callback(parser, iter, command);
	command_build(parser, iter, command);
}

static int	must_end(t_parser *parser, t_token *token)
{
	return (
		parser->status != PARSER_STATUS_DEFAULT
		|| (parser->subshell > 0 && token_is(token, TOK_C_PARENTHESIS))
	);
}

void	command_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	token = (t_token *)iter->data;
	if (must_end(parser, token))
		return ;
	else if (command_is_start_of(token, COMMAND_COMPOUND))
		command_build_loop(command_compound_build, parser, iter, command);
	else if (command_is_start_of(token, COMMAND_LIST))
		command_list_build(parser, iter, command);
	else if (command_is_start_of(token, COMMAND_PIPELINE))
		command_pipeline_build(parser, iter, command);
	else if (command_is_start_of(token, COMMAND_SIMPLE))
		command_build_loop(command_simple_build, parser, iter, command);
	else
		parser_unexpected_token(parser, token);
}
