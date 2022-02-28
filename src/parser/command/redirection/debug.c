/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 21:08:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	redirections_debug(t_lst *redirections)
{
	t_iter			iter;
	t_redirection	*redirection;

	iter_init(&iter, redirections, ASC);
	while (iter_next(&iter))
	{
		redirection = (t_redirection *)iter.data;
		ftprintf("%s %s ", redirection->type->raw, redirection->arg->raw);
	}
}
