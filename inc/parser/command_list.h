/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:56:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST_H
# define COMMAND_LIST_H

typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

typedef struct s_command_list
{
	t_token	*type;
}	t_command_list;

void	command_list_build(
			t_parser *parser,
			t_iter *iter,
			t_command **command);
void	command_list_run(t_command *command);
void	command_list_debug(t_command *command);

#endif
