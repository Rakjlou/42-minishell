/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_compound.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:56:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_COMPOUND_H
# define COMMAND_COMPOUND_H

struct						s_command;
typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

typedef enum e_command_compound_type
{
	COMPOUND_GROUPING
}	t_command_compound_type;

typedef struct s_command_compound
{
	t_command_compound_type	type;
	struct s_command		*tree;
}	t_command_compound;

void	command_compound_build(
			t_parser *parser,
			t_iter *iter,
			t_command **command);
void	command_compound_run(t_command *command);
void	command_compound_debug(t_command *command, int level);

#endif
