/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:40:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_pipeline_run(t_command *command)
{
	t_command_list	*list_data;
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	list_data = &command->data.list;
	(void)list_data;
	exec_tree_dispatch(before);
	exec_tree_dispatch(after);
}
