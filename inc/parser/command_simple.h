/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_simple.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 18:45:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_SIMPLE_H
# define COMMAND_SIMPLE_H

typedef struct s_command_simple
{
	t_lst	args;
	t_lst	redirections;
}	t_command_simple;

#endif
