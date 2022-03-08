/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 18:49:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

void	redirections_run(t_command *command, t_lst *redirections)
{
	t_redirection	*redirection;
	t_iter			iter;

	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = iter.data;
		redirection->arg->expanded = wordexp(redirection->arg->raw);
		if (ft_cmatrix_size(redirection->arg->expanded) > 1
			|| ft_cmatrix_size(redirection->arg->expanded) == 0)
		{
			command->status = 1;
			ftfprintf(
				STDERR_FILENO,
				"%s: %s: ambiguous redirect\n",
				"minishell",
				redirection->arg->raw);
		}
	}
	return ;
}
