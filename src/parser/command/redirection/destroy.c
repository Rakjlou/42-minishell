/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 17:58:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ftprintf.h"
#include "parser/parser.h"

static void	redirectrion_destroy_error(t_redirection *redirection)
{
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		redirection->filename,
		strerror(errno));
}

static void	redirection_default_destroy(t_redirection *redirection)
{
	if (redirection->fd > 0 && close(redirection->fd) == -1)
		redirectrion_destroy_error(redirection);
}

static void	heredoc_destroy(t_redirection *redirection)
{
	redirection_default_destroy(redirection);
	if (redirection->filename != NULL)
	{
		if (unlink(redirection->filename) == -1)
			redirectrion_destroy_error(redirection);
		free(redirection->filename);
	}
	free(redirection->heredoc_line);
	free(redirection->heredoc_stop);
}

static void	redirection_destroy(void *raw)
{
	t_redirection	*redirection;

	redirection = raw;
	if (token_is(redirection->type, TOK_DLESS))
		heredoc_destroy(redirection);
	else
		redirection_default_destroy(redirection);
	free(raw);
}

void	redirections_destroy(t_lst *redirections)
{
	lst_destroy_nodes(redirections, redirection_destroy);
}
