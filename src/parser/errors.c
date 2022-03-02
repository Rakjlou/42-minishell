/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:53:08 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 20:56:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser/parser.h"
#include "lexer/errors.h"

void	parser_unexpected_token(t_parser *parser, t_token *token)
{
	lexer_syntax_error(&parser->lexer, token, LEXER_UNEXPECTED_TOK_ERROR);
	parser->status = PARSER_LEXER_ERROR;
}

void	parser_internal_error(t_parser *parser)
{
	perror("minishell");
	parser->status = PARSER_INTERNAL_ERROR;
}
