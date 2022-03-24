/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 16:19:32 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftprintf.h"
#include "shell.h"
#include "parser/parser.h"

int	pipeline_handle(t_command *command)
{
	int	current_fd[2];

	if (!pipeline_is_active())
		return (1);
	current_fd[PIPE_WRITE] = command->parent->data.pipeline.fds[PIPE_WRITE];
	current_fd[PIPE_READ] = command->parent->data.pipeline.fds[PIPE_READ];
	if (pipeline_is_first())
	{
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(current_fd[PIPE_READ]);
		ftfprintf(STDERR_FILENO, "pipeline_is_first\n");
		return (1);
	}
	else if (pipeline_is_middle())
	{
		dup2(command->parent->parent->data.pipeline.fds[PIPE_READ], _shell()->pipeline.pipe_in);
		dup2(current_fd[PIPE_WRITE], _shell()->pipeline.pipe_out);
		close(command->parent->parent->data.pipeline.fds[PIPE_READ]);
		close(command->parent->data.pipeline.fds[PIPE_READ]);
		ftfprintf(STDERR_FILENO, "pipeline_is_middle\n");
	}
	else if (pipeline_is_last())
	{
		ftfprintf(STDERR_FILENO, "pipeline_is_last\n");
		dup2(current_fd[PIPE_READ], _shell()->pipeline.pipe_in);
		close(current_fd[PIPE_WRITE]);
	}
	return (1);
}
