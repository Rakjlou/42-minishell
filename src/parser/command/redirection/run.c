/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 21:31:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

#include <unistd.h>

int		open_file(char *filename, int flags, int *fd)
{
	int	candidate;

	candidate = open(filename, flags);

}

void	redirection_handle(t_command *command, t_redirection *redirection)
{
	char	*filename;

	filename = redirection->arg->expanded[0];
	if (token_is(redirection->type, TOK_SGREAT))
		redirection->fd = open(filename, O_CREAT);
}

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

void	redirections_run(t_command *command, t_lst *redirections)
{
	t_redirection	*redirection;
	t_iter			iter;

	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		if (!token_is(redirection->type, TOK_DLESS))
		{
			redirection->arg->expanded = wordexp(redirection->arg->raw);
			if (is_ambiguous(redirection))
				ambiguous_error(command, redirection);
		}
		redirection_handle(command, redirection);
	}
	return ;
}
