/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:47:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	command_compound_run(t_command *command)
{
	t_command_compound	*compound_data;
	t_command			*before;
	t_command			*after;
	t_command			*subshell;

	(void)before;
	(void)after;
	before = command->before;
	after = command->after;
	compound_data = &command->data.compound;
	subshell = compound_data->tree;
	exec_tree_dispatch(subshell);
	exec_tree_dispatch(after);
}
