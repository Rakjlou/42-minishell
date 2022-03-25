/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 17:54:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include <fcntl.h>

typedef struct s_command	t_command;
typedef struct s_token		t_token;
typedef struct s_lst		t_lst;
typedef struct s_parser		t_parser;
typedef struct s_iter		t_iter;

typedef enum e_redirection_is
{
	R_OUT,
	R_IN,
	R_HERE,
	R_IN_SIMPLE,
}	t_redirection_is;

typedef struct s_redirection
{
	t_token	*type;
	t_token	*arg;
	char	*filename;
	char	*heredoc_line;
	char	*heredoc_stop;
	int		fd;
	int		stdout_fd;
	int		stdin_fd;
}	t_redirection;

int		redirections_run(t_command *command, t_lst *redirections);
void	redirections_stop(t_lst *redirections);
void	redirections_debug(t_lst *redirections);
void	redirections_destroy(t_lst *redirections);

void	redirection_open_file_error(t_command *cmd, t_redirection *redirection);
int		redirection_open_file(t_command *command, t_redirection *redirection);
void	redirection_build(t_parser *parser, t_iter *iter, t_lst *lst);

int		redirection_is(t_redirection *redirection, t_redirection_is thing);

int		heredoc_request(t_parser *parser, t_redirection *redirection);
char	*heredoc_get_stop_token(t_redirection *redirection);
int		heredoc_open(t_parser *parser, t_redirection *redirection);
void	heredoc_close(t_parser *parser, t_redirection *redirection);

#endif
