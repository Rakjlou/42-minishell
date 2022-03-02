/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 03:45:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/parser.h"

void	exec_tree_destroy(t_command *command)
{
	t_command	*before;
	t_command	*after;

	if (command == NULL)
		return ;
	before = command->before;
	after = command->after;
	if (command->type == COMMAND_SIMPLE)
	{
		lst_destroy_nodes(&command->data.simple.redirections, free);
		lst_destroy_nodes(&command->data.simple.args, NULL);
	}
	else if (command->type == COMMAND_COMPOUND)
	{
		lst_destroy_nodes(&command->data.compound.redirections, free);
		exec_tree_destroy(command->data.compound.tree);
	}
	free(command);
	exec_tree_destroy(before);
	exec_tree_destroy(after);
}
