/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:28:22 by nsierra-         ###   ########.fr       */
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

static void	ambiguous_error(t_command *command, t_redirection *redirection)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: ambiguous redirect\n",
		"minishell",
		redirection->arg->raw);
}

static int	expand_redirection(
	t_command *command,
	t_redirection *redirection)
{
	redirection->arg->expanded = wordexp(redirection->arg->raw);
	if (is_ambiguous(redirection))
		return (ambiguous_error(command, redirection), 0);
	redirection->filename = redirection->arg->expanded[0];
	return (1);
}

static void	redirection_start(t_command *command, t_redirection *redirection)
{
	if (!redirection_is(redirection, R_HERE)
		&& !redirection_open_file(command, redirection))
		return ;
	else if (redirection_is(redirection, R_OUT))
	{
		redirection->stdout_fd = dup(STDOUT_FILENO);
		if (redirection->stdout_fd < 0
			|| dup2(redirection->fd, STDOUT_FILENO) < 0)
			return ((command->status = EXIT_FAILURE), perror("minishell"));
	}
	else if (redirection_is(redirection, R_IN))
	{
		redirection->stdin_fd = dup(STDIN_FILENO);
		if (redirection->stdin_fd < 0
			|| dup2(redirection->fd, STDIN_FILENO) < 0)
			return ((command->status = EXIT_FAILURE), perror("minishell"));
	}
}

void	redirections_run(t_command *command, t_lst *redirections)
{
	t_redirection	*redirection;
	t_iter			iter;

	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		if (!token_is(redirection->type, TOK_DLESS)
			&& !expand_redirection(command, redirection))
			return ;
		redirection_start(command, redirection);
	}
	return ;
}
