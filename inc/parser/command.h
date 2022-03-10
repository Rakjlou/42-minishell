/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 23:46:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "parser/command_simple.h"
# include "parser/command_list.h"
# include "parser/command_compound.h"

typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

typedef enum e_command_type
{
	COMMAND_SIMPLE,
	COMMAND_PIPELINE,
	COMMAND_LIST,
	COMMAND_COMPOUND,
	COMMAND_TYPE_COUNT
}	t_command_type;

typedef union u_command_data
{
	t_command_simple	simple;
	t_command_list		list;
	t_command_compound	compound;
}	t_command_data;

typedef struct s_command
{
	t_command_type		type;
	t_command_data		data;
	int					status;
	char				**argv;
	struct s_command	*before;
	struct s_command	*after;
}	t_command;

t_lst	*command_get_redirections(t_command *command);
t_lst	*command_get_args(t_command *command);
int		command_is(t_command *command, t_command_type type);
int		command_is_empty(t_command *command);
int		command_is_start_of(t_token *token, t_command_type type);
void	command_build(
			t_parser *parser,
			t_iter *iter,
			t_command **command);

void	command_pipeline_run(t_command *command);
void	command_pipeline_build(t_parser *parser, t_iter *i, t_command **cmd);
void	command_pipeline_debug(t_command *command);

/* Exec */
void	command_exec(t_command *command);
void	builtin_exec(t_command *command);

int		command_find_path(t_command *command, char **path);
int		command_build_argv(t_command *command);

void	command_set_last(t_command *command);
void	command_set_last_status(t_command *command, int status);

void	command_error(t_command *command);
void	command_file_error_errcode(t_command *command, int errcode, int status);
void	command_file_error_message(t_command *command, char *message);
void	command_not_found_error(t_command *command);
void	build_argv_error(t_command *command);
char	*sigstr(int sig);

#endif
