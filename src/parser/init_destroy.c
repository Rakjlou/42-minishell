/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 21:12:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parser/parser.h"

void	parser_init(char *line)
{
	t_parser	*parser;

	parser = _parser();
	ft_bzero(parser, sizeof(t_parser));
	parser->user_input = line;
	lexer_init(&parser->lexer, line);
	lexer_build_token_list(&parser->lexer);
}

void	parser_destroy(void)
{
	t_parser	*parser;

	parser = _parser();
	exec_tree_destroy(parser->tree);
	lexer_destroy(&parser->lexer);
	free(parser->user_input);
	ft_bzero(parser, sizeof(t_parser));
}
