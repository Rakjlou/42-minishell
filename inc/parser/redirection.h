/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:05:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

typedef struct s_redirection
{
	t_token	*type;
	t_token	*arg;
}	t_redirection;

void	redirections_debug(t_lst *redirections);
void	redirection_build(t_parser *parser, t_iter *iter, t_lst *lst);
int		heredoc_request(t_parser *parser, t_redirection *redirection);


#endif
