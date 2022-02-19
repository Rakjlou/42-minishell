/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 02:47:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define PARSER_DEBUG 1

# include "lexer/lexer.h"
# include "parser/command.h"

typedef struct s_redirection
{
	t_token	*type;
	t_token	*arg;
}	t_redirection;

typedef enum e_parser_status
{
	PARSER_STATUS_DEFAULT,
	PARSER_STATUS_FINISHED,
	PARSER_LEXER_ERROR,
	PARSER_INTERNAL_ERROR
}	t_parser_status;

typedef struct s_parser
{
	t_parser_status	status;
	t_lexer			lexer;
	t_command		*tree;
	int				subshell;
}	t_parser;

void	parser_init(t_parser *parser, char *line);
void	parser_destroy(t_parser *parser);
void	parser_execute(char *line);

void	parser_tree_print(t_command *tree, int level);
void	parser_tree_build(t_parser *parser);
void	parser_tree_build_command(t_parser *parser, t_iter *i, t_command **cmd);

void	parser_unexpected_token(t_parser *parser, t_token *token);
void	parser_internal_error(t_parser *parser);

void	command_simple_consume(t_parser *parser, t_iter *iter, t_command **cmd);
void	command_simple_debug(t_command *command);

void	command_list_consume(t_parser *parser, t_iter *iter, t_command **cmd);
void	command_list_debug(t_command *command);

void	command_pipeline_consume(t_parser *parser, t_iter *i, t_command **cmd);
void	command_pipeline_debug(t_command *command);

void	command_compound_consume(t_parser *parser, t_iter *iter, t_command **c);
void	command_compound_debug(t_command *command, int level);

#endif
