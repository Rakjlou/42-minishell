/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_compound.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 22:54:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_COMPOUND_H
# define COMMAND_COMPOUND_H

typedef enum
{
	COMPOUND_GROUPING
}	t_command_compound_type;

typedef struct s_command_compound
{
	t_command_compound_type	type;
	t_lst					lst;
}	t_command_compound;

#endif
