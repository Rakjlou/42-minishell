/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_simple.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 03:51:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_SIMPLE_H
# define COMMAND_SIMPLE_H

typedef struct s_command	t_command;
typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

typedef struct s_command_simple
{
	t_lst	args;
	t_lst	redirections;
}	t_command_simple;

void	command_simple_consume(
			t_parser *parser,
			t_iter *iter,
			t_command **command);
void	command_simple_debug(t_command *command);

#endif
