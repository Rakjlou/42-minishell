/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/22 18:15:31 by nsierra-         ###   ########.fr       */
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

static int	try_dup(int *dest, int source)
{
	*dest = dup(source);
	if (*dest < 0)
		return (0);
	return (1);
}

static int	try_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
		return (0);
	return (1);
}

static int	handle_new_pipe(t_command *command)
{
	t_command_pipeline	*pipeline;
	int					pipe_fd[2];

	pipeline = &command->data.pipeline;
	_shell()->exec.pipeline = 1;
	if (!try_dup(&pipeline->in, _shell()->exec.pipe_in)
		|| !try_dup(&pipeline->out, _shell()->exec.pipe_out)
		|| !try_pipe(pipe_fd))
		return (command_error(command), 0);
	return (1);
}

void	command_pipeline_run(t_command *command)
{
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	if (is_new_pipe(command) && !handle_new_pipe(command))
		handle_new_pipe(command);
	else if (is_inner_pipe(command))
		ftprintf("INNER PIPE\n");
	exec_tree_dispatch(before);
	exec_tree_dispatch(after);
}
