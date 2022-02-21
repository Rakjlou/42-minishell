/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 03:39:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	exec_tree_build_command(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	if (*command == NULL)
	{
		*command = ft_calloc(sizeof(t_command), 1);
		if (*command == NULL)
			return (parser_internal_error(parser));
	}
	command_simple_consume(parser, iter, command);
}

void	exec_tree_build(t_parser *parser)
{
	t_iter	iter;

	if (parser->lexer.status != LEXER_STATUS_DEFAULT)
		parser->status = PARSER_LEXER_ERROR;
	iter_init(&iter, &parser->lexer.tokens, ASC);
	exec_tree_build_command(parser, &iter, &parser->tree);
}
