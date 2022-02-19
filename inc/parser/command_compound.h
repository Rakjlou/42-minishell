/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_compound.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 02:54:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_COMPOUND_H
# define COMMAND_COMPOUND_H

struct	s_command;

typedef enum e_command_compound_type
{
	COMPOUND_GROUPING
}	t_command_compound_type;

typedef struct s_command_compound
{
	t_command_compound_type	type;
	struct s_command		*tree;
}	t_command_compound;

#endif
