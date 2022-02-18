/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:42:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 02:25:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#include "parser/parser.h"
#include "lexer/errors.h"

static void	parser_init(t_parser *parser, char *line)
{
	ft_bzero(parser, sizeof(t_parser));
	lexer_init(&parser->lexer, line);
	lexer_build_token_list(&parser->lexer);
}

static void	parser_destroy(t_parser *parser)
{
	lexer_destroy(&parser->lexer);
}

static void	parser_unexpected_token(t_parser *parser, t_token *token)
{
	lexer_syntax_error(&parser->lexer, token, LEXER_UNEXPECTED_TOK_ERROR);
	parser->status = PARSER_LEXER_ERROR;
}

static void	parser_internal_error(t_parser *parser)
{
	perror("minishell");
	parser->status = PARSER_INTERNAL_ERROR;
}

static t_lst	*command_get_redirections(t_command *command)
{
	return (&command->data.simple.redirections);
}

static t_lst	*command_get_args(t_command *command)
{
	return (&command->data.simple.args);
}

static void	tree_print_repeatc(unsigned char c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
		ft_putchar_fd(c, STDOUT_FILENO);
}

static void	tree_print_simple_command(t_command *command)
{
	t_iter	iter;
	t_token	*token;

	iter_init(&iter, &command->data.simple.args, ASC);
	ftprintf("Simple ");
	while (iter_next(&iter))
	{
		token = (t_token *)iter.data;
		ftprintf("%s ", token->raw);
	}
	ftprintf("\n");
}


static void	tree_print_command(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		tree_print_simple_command(command);
	else if (command->type == COMMAND_LIST)
		ftprintf("%s\n", (char *)command->data.list.type->raw);
	else
		ftprintf("Unknown\n");
}

static void	tree_print(t_command *tree, int level)
{
	if (tree == NULL)
		return ;
	tree_print_repeatc(' ', level * 4);
	tree_print_command(tree);
	++level;
	tree_print(tree->before, level);
	tree_print(tree->after, level);
}

static void	consume_redirection(t_parser *parser, t_iter *iter, t_command **cmd);
static void	consume_list(t_parser *parser, t_iter *iter, t_command **command);
static void	parser_tree_build_command(
	t_parser *parser,
	t_iter *iter,
	t_command **command);

static void	command_hydrate(t_parser *parser, t_iter *iter, t_command **command)
{
	t_token		*token;

	if (!iter_next(iter))
		return ;
	token = (t_token *)iter->data;
	if (token_is_redirection_operator(token))
		consume_redirection(parser, iter, command);
	else if (token_is_logical_operator(token))
		consume_list(parser, iter, command);
	else if (!lst_push_back(command_get_args(*command), token))
		parser_internal_error(parser);
	else
		command_hydrate(parser, iter, command);
}

static void	consume_redirection(t_parser *parser, t_iter *iter, t_command **cmd)
{
	t_redirection	candidate;
	t_redirection	*redirection;

	candidate.type = (t_token *)iter->data;
	if (!iter_next(iter))
	{
		parser_unexpected_token(parser, NULL);
		return ;
	}
	candidate.arg = (t_token *)iter->data;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
	{
		parser_internal_error(parser);
		return ;
	}
	redirection = ft_memcpy(redirection, &candidate, sizeof(t_redirection));
	if (!lst_push_back(command_get_redirections(*cmd), redirection))
		parser_internal_error(parser);
}

static int	command_is_eof(t_command *command)
{
	return (
		command->type == COMMAND_SIMPLE
		&& command->data.simple.args.size == 0
		&& command->data.simple.redirections.size == 0
	);
}

static void	consume_list(t_parser *parser, t_iter *iter, t_command **command)
{
	t_command	*list;

	if (*command == NULL)
		parser_unexpected_token(parser, (t_token *)iter->data);
	list = ft_calloc(sizeof(t_command), 1);
	if (list == NULL)
		parser_internal_error(parser);
	list->type = COMMAND_LIST;
	list->data.list.type = (t_token *)iter->data;
	list->before = *command;
	parser_tree_build_command(parser, iter, &list->after);
	if (list->after == NULL || command_is_eof(list->after))
		parser_unexpected_token(parser, (t_token *)iter->data);
	else
		*command = list;
}

static void	parser_tree_build_command(
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
	command_hydrate(parser, iter, command);
}

static void	parser_tree_build(t_parser *parser)
{
	t_iter	iter;

	if (parser->lexer.status != LEXER_STATUS_DEFAULT)
		parser->status = PARSER_LEXER_ERROR;
	iter_init(&iter, &parser->lexer.tokens, ASC);
	parser_tree_build_command(parser, &iter, &parser->tree);
}

void	parser_execute(char *line)
{
	t_parser	parser;

	parser_init(&parser, line);
	parser_tree_build(&parser);
	tree_print(parser.tree, 0);
	parser_destroy(&parser);
}
