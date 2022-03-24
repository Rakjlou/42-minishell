/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 18:13:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	pipeline_get_parent_write(t_command *command)
{
	t_command	*parent;

	parent = pipeline_get_parent(command);
	return (parent->data.pipeline.fds[PIPE_WRITE]);
}

int	pipeline_get_parent_read(t_command *command)
{
	t_command	*parent;

	parent = pipeline_get_parent(command);
	return (parent->data.pipeline.fds[PIPE_READ]);
}

int	pipeline_get_previous_write(t_command *command)
{
	t_command	*previous;

	previous = pipeline_get_previous(command);
	return (previous->data.pipeline.fds[PIPE_WRITE]);
}

int	pipeline_get_previous_read(t_command *command)
{
	t_command	*previous;

	previous = pipeline_get_previous(command);
	return (previous->data.pipeline.fds[PIPE_READ]);
}
