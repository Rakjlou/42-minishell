/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/21 19:23:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#include "shell.h"

static int	is_inner_pipe(t_command *command)
{
	return (
		command_is(command->after, COMMAND_PIPELINE)
		|| (command_is(command->after, COMMAND_COMPOUND)
			&& command_is(command->after->after, COMMAND_PIPELINE))
	);
}

static int	is_new_pipe(t_command *command)
{
	return (
		!command_is(command->parent, COMMAND_PIPELINE)
		&& _shell()->exec.pipeline == 0
	);
}

void	pipeline_close(void)
{
	ftprintf("CLOSING PIPELINE\n");
	_shell()->exec.pipeline = 0;
}

void	command_pipeline_run(t_command *command)
{
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	ftprintf("===\n");
	if (is_new_pipe(command))
	{
		ftprintf("NEW PIPE\n");
		_shell()->exec.pipeline = 1;
	}
	if (is_inner_pipe(command))
		ftprintf("INNER PIPE\n");
	exec_tree_dispatch(before);
	exec_tree_dispatch(after);
}
