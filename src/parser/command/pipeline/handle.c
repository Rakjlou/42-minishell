/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 17:38:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"

t_command	*pipeline_get_parent(t_command *command)
{
	if (command_is(command->parent, COMMAND_PIPELINE))
		return (command->parent);
	else if (command_is(command->parent, COMMAND_LIST))
		return (command->parent->parent);
	else
		return (NULL);
}

t_command	*pipeline_get_previous(t_command *command)
{
	t_command	*parent;

	parent = pipeline_get_parent(command);
	if (parent == NULL)
		return (NULL);
	return (pipeline_get_parent(parent));
}

int	pipeline_handle(t_command *command)
{
	int	current_fd[2];

	if (!pipeline_is_active())
		return (1);
	current_fd[PIPE_WRITE] = pipeline_get_parent(command)->data.pipeline.fds[PIPE_WRITE];
	current_fd[PIPE_READ] = pipeline_get_parent(command)->data.pipeline.fds[PIPE_READ];
	if (pipeline_is_first())
	{
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(current_fd[PIPE_READ]);
		return (1);
	}
	else if (pipeline_is_middle())
	{
		dup2(pipeline_get_previous(command)->data.pipeline.fds[PIPE_READ], _shell()->pipeline.pipe_in);
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(pipeline_get_previous(command)->data.pipeline.fds[PIPE_READ]);
		close(pipeline_get_parent(command)->data.pipeline.fds[PIPE_READ]);
	}
	else if (pipeline_is_last())
	{
		dup2(current_fd[PIPE_READ], _shell()->pipeline.pipe_in);
		close(current_fd[PIPE_WRITE]);
	}
	return (1);
}
