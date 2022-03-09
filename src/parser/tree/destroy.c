/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:50:59 by nsierra-         ###   ########.fr       */
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
		redirections_destroy(&command->data.simple.redirections);
		lst_destroy_nodes(&command->data.simple.args, NULL);
		if (command->argv != NULL)
			ft_cmatrix_free(command->argv);
	}
	else if (command->type == COMMAND_COMPOUND)
	{
		redirections_destroy(&command->data.compound.redirections);
		exec_tree_destroy(command->data.compound.tree);
	}
	free(command);
	exec_tree_destroy(before);
	exec_tree_destroy(after);
}
