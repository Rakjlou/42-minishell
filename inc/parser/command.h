/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 18:45:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "parser/command_simple.h"
# include "parser/command_list.h"

typedef enum e_command_type
{
	COMMAND_SIMPLE,
	COMMAND_PIPELINE,
	COMMAND_LIST,
	COMMAND_TYPE_COUNT
}	t_command_type;

typedef union u_command_data
{
	t_command_simple	simple;
	t_command_list		list;
}	t_command_data;

typedef struct s_command
{
	t_command_type		type;
	t_command_data		data;
	int					exit_status;
	struct s_command	*before;
	struct s_command	*after;
}	t_command;

t_lst	*command_get_redirections(t_command *command);
t_lst	*command_get_args(t_command *command);
int		command_is_empty(t_command *command);

#endif
