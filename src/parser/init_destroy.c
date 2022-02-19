/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 03:24:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	parser_init(t_parser *parser, char *line)
{
	ft_bzero(parser, sizeof(t_parser));
	lexer_init(&parser->lexer, line);
	lexer_build_token_list(&parser->lexer);
}

void	parser_destroy(t_parser *parser)
{
	lexer_destroy(&parser->lexer);
	parser_tree_destroy(parser->tree);
	parser->tree = NULL;
}
