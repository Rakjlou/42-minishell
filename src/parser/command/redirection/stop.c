/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:25:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser/parser.h"
#include "ftprintf.h"

static void	redirection_stop(t_redirection *redirection)
{
	if (redirection_is(redirection, R_OUT))
	{
		dup2(redirection->stdout_fd, STDOUT_FILENO);
		close(redirection->stdout_fd);
	}
	else if (redirection_is(redirection, R_IN))
	{
		dup2(redirection->stdin_fd, STDIN_FILENO);
		close(redirection->stdin_fd);
	}
}

void	redirections_stop(t_lst *redirections)
{
	t_iter			iter;

	iter_init(&iter, redirections, DESC);
	while (iter_next(&iter))
		redirection_stop(iter.data);
}
