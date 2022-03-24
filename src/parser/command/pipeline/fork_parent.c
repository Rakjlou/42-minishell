/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 14:18:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

void	pipeline_fork_parent(t_command *command)
{
	if (pipeline_is_first())
	{
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
	}
	else if (pipeline_is_last())
	{
		close(command->parent->data.pipeline.fds[PIPE_READ]);
		_shell()->pipeline.r--;
		pipeline_close();
	}
	else if (pipeline_is_middle())
	{
		close(command->parent->parent->data.pipeline.fds[PIPE_READ]);
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
		_shell()->pipeline.r--;
	}
}
