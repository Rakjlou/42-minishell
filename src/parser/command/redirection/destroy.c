/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 20:54:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ftprintf.h"
#include "parser/parser.h"

static void	redirection_destroy(void *raw)
{
	t_redirection	*redirection;

	redirection = raw;
	if (redirection->fd > 0 && close(redirection->fd) == -1)
	{
		ftfprintf(
			STDERR_FILENO,
			"%s: %s: %s\n",
			"minishell",
			redirection->filename,
			strerror(errno));
	}
	free(raw);
}

void	redirections_destroy(t_lst *redirections)
{
	lst_destroy_nodes(redirections, redirection_destroy);
}
