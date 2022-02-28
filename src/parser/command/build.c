/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 21:31:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	command_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	if (parser->status != PARSER_STATUS_DEFAULT)
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
