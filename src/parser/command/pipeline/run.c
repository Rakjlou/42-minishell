/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/15 18:56:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser/parser.h"

void	command_pipeline_run(t_command *command)
{
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	if (!command_is(command->parent, COMMAND_PIPELINE))
		puts("NEW PIPE");
	if (command_is(after, COMMAND_PIPELINE))
		puts("INNER PIPE");
	else
		puts("END PIPE");
	exec_tree_dispatch(before);
	exec_tree_dispatch(after);
}
