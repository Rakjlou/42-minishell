/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 22:23:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"

static void	handle_first(t_command *command)
{
	t_command	*parent;

	parent = pipeline_get_parent(command);
	if (parent == NULL)
		return ;
	close(parent->data.pipeline.fds[PIPE_WRITE]);
	_shell()->pipeline.l--;
}

static void	handle_middle(t_command *command)
{
	t_command	*parent;
	t_command	*previous;

	parent = pipeline_get_parent(command);
	previous = pipeline_get_previous(command);
	if (parent == NULL || previous == NULL)
		return ;
	close(previous->data.pipeline.fds[PIPE_READ]);
	close(parent->data.pipeline.fds[PIPE_WRITE]);
	_shell()->pipeline.l--;
	_shell()->pipeline.r--;
}

static void	handle_last(t_command *command)
{
	t_command	*parent;

	parent = pipeline_get_parent(command);
	if (parent == NULL)
		return ;
	close(parent->data.pipeline.fds[PIPE_READ]);
	_shell()->pipeline.r--;
	pipeline_close();
}

void	pipeline_fork_parent(t_command *command)
{
	if (pipeline_is_first())
		handle_first(command);
	else if (pipeline_is_last())
		handle_last(command);
	else if (pipeline_is_middle())
		handle_middle(command);
}
