/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 17:30:23 by nsierra-         ###   ########.fr       */
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
	if (command == NULL)
		return (NULL);
	else if (command_is(command->parent, COMMAND_PIPELINE))
		return (command->parent);
	return (pipeline_get_parent(command->parent));
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
	if (!pipeline_is_active())
		return (1);
	else if (pipeline_is_first())
	{
		dup2(pipeline_get_parent_write(command), _shell()->pipeline.pipe_out);
		close(pipeline_get_parent_read(command));
		return (1);
	}
	else if (pipeline_is_middle())
	{
		dup2(pipeline_get_previous_read(command), _shell()->pipeline.pipe_in);
		dup2(pipeline_get_parent_write(command), _shell()->pipeline.pipe_out);
		close(pipeline_get_previous_read(command));
		close(pipeline_get_parent_read(command));
	}
	else if (pipeline_is_last())
	{
		dup2(pipeline_get_parent_read(command), _shell()->pipeline.pipe_in);
		close(pipeline_get_parent_write(command));
	}
	return (1);
}
