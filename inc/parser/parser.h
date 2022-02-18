/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 01:37:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define PARSER_DEBUG 0

# include "lexer/lexer.h"

typedef struct s_redirection
{
	t_token	*type;
	t_token	*arg;
}	t_redirection;

typedef enum e_command_type
{
	COMMAND_SIMPLE,
	COMMAND_PIPELINE,
	COMMAND_LIST,
	COMMAND_TYPE_COUNT
}	t_command_type;

typedef struct s_command_simple
{
	t_lst	args;
	t_lst	redirections;
}	t_command_simple;

typedef struct s_command_list
{
	t_token	*type;
}	t_command_list;

typedef union u_command_data
{
	t_command_simple	simple;
	t_command_list		list;
}	t_command_data;

typedef struct s_command
{
	t_command_type		type;
	t_command_data		data;
	int					exit_status;
	struct s_command	*before;
	struct s_command	*after;
}	t_command;

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
}	t_parser;

void	parser_execute(char *line);

#endif
