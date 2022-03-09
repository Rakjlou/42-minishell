/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 20:53:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include <fcntl.h>

typedef struct s_command	t_command;

typedef struct s_redirection
{
	t_token	*type;
	t_token	*arg;
	char	*filename;
	int		fd;
}	t_redirection;

void	redirections_run(t_command *command, t_lst *redirections);
void	redirections_debug(t_lst *redirections);
void	redirections_destroy(t_lst *redirections);

int		redirection_open_file(t_command *command, t_redirection *redirection);
void	redirection_build(t_parser *parser, t_iter *iter, t_lst *lst);

int		heredoc_request(t_parser *parser, t_redirection *redirection);

#endif
