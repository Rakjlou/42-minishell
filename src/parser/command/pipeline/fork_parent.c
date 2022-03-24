/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 15:55:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"

void	pipeline_fork_parent(t_command *command)
{
	if (pipeline_is_first())
	{
		ftfprintf(STDERR_FILENO, "PARENT pipeline_is_first\n");
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
	}
	else if (pipeline_is_last())
	{
		ftfprintf(STDERR_FILENO, "PARENT pipeline_is_last\n");
		close(command->parent->data.pipeline.fds[PIPE_READ]);
		_shell()->pipeline.r--;
		pipeline_close();
	}
	else if (pipeline_is_middle())
	{
		ftfprintf(STDERR_FILENO, "PARENT pipeline_is_middle\n");
		close(command->parent->parent->data.pipeline.fds[PIPE_READ]);
		close(command->parent->data.pipeline.fds[PIPE_WRITE]);
		_shell()->pipeline.l--;
		_shell()->pipeline.r--;
	}
}
