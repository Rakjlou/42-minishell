/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 19:24:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#include "shell.h"

static int	try_pipe(int fds[2])
{
	if (pipe(fds) < 0)
		return (0);
	return (1);
}

static void	incr_lr(void)
{
	_shell()->pipeline.l++;
	_shell()->pipeline.r++;
}

void	command_pipeline_run(t_command *command)
{
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	incr_lr();
	if (!try_pipe(command->data.pipeline.fds))
		return (command_error(command));
	exec_tree_dispatch(before);
	exec_tree_dispatch(after);
}
