/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:33:39 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 19:46:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ftprintf.h"

void	exec_tree_dispatch(t_command *node)
{
	if (node == NULL)
		return ;
	else if (node->type == COMMAND_SIMPLE)
		command_simple_run(node);
	else if (node->type == COMMAND_LIST)
		command_list_run(node);
	else if (node->type == COMMAND_PIPELINE)
		command_pipeline_run(node);
	else if (node->type == COMMAND_COMPOUND)
		command_compound_run(node);
}

void	exec_tree_run(t_command *tree)
{
	exec_tree_dispatch(tree);
}
