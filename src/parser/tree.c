/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 18:47:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftprintf.h"
#include "parser/parser.h"

static void	tree_print_repeatc(unsigned char c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
		ft_putchar_fd(c, STDOUT_FILENO);
}

static void	tree_print_command(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		command_simple_debug(command);
	else if (command->type == COMMAND_LIST)
		command_list_debug(command);
	else
		ftprintf("Unknown\n");
}

void	parser_tree_print(t_command *tree, int level)
{
	if (tree == NULL)
		return ;
	tree_print_repeatc(' ', level * 4);
	tree_print_command(tree);
	++level;
	parser_tree_print(tree->before, level);
	parser_tree_print(tree->after, level);
}

void	parser_tree_build_command(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	if (*command == NULL)
	{
		*command = ft_calloc(sizeof(t_command), 1);
		if (*command == NULL)
		{
			parser_internal_error(parser);
			return ;
		}
	}
	command_simple_consume(parser, iter, command);
}

void	parser_tree_build(t_parser *parser)
{
	t_iter	iter;

	if (parser->lexer.status != LEXER_STATUS_DEFAULT)
		parser->status = PARSER_LEXER_ERROR;
	iter_init(&iter, &parser->lexer.tokens, ASC);
	parser_tree_build_command(parser, &iter, &parser->tree);
}
