/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/22 20:28:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static int	is_ambiguous(t_redirection *redirection)
{
	return (
		ft_cmatrix_size(redirection->arg->expanded) > 1
		|| ft_cmatrix_size(redirection->arg->expanded) == 0
		|| ft_strlen(redirection->arg->expanded[0]) == 0
	);
}

static int	redirection_setup(
	t_command *command,
	t_redirection *redirection)
{
	if (redirection_is(redirection, R_HERE))
		return (1);
	redirection->arg->expanded = wordexp(redirection->arg->raw);
	if (is_ambiguous(redirection))
	{
		command_set_last_status(command, EXIT_FAILURE);
		ftfprintf(
			STDERR_FILENO,
			"%s: %s: ambiguous redirect\n",
			"minishell",
			redirection->arg->raw);
		return (0);
	}
	redirection->filename = redirection->arg->expanded[0];
	return (redirection_open_file(command, redirection));
}

static void	redirection_start(
	t_command *command,
	t_redirection *redirection,
	int *save,
	int duplicated)
{
	*save = dup(duplicated);
	if (*save < 0 || dup2(redirection->fd, duplicated) < 0)
	{
		return (
			command_set_last_status(command, EXIT_FAILURE),
			perror("minishell")
		);
	}
}

static void	redirection_dispatch(t_command *command, t_redirection *redirection)
{
	if (redirection_is(redirection, R_OUT))
	{
		redirection_start(
			command,
			redirection,
			&redirection->stdout_fd,
			STDOUT_FILENO);
	}
	else if (redirection_is(redirection, R_IN))
	{
		redirection_start(
			command,
			redirection,
			&redirection->stdin_fd,
			STDIN_FILENO);
	}
}

int	redirections_run(t_command *command, t_lst *redirections)
{
	t_redirection	*redirection;
	t_iter			iter;

	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		if (!redirection_setup(command, redirection))
			return (0);
		redirection_dispatch(command, redirection);
	}
	return (1);
}
