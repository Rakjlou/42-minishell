/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:42:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 20:42:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	parser_execute(char *line)
{
	t_parser	parser;

	parser_init(&parser, line);
	parser_tree_build(&parser);
	parser_tree_print(parser.tree, 0);
	parser_destroy(&parser);
}
