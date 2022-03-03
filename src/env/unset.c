/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:30:33 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:37:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	free_content(void *content)
{
	env_content_destroy((t_env_content *)content);
}

void	env_unset(t_lst *env, char *key)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, env, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (ft_strncmp(content->key, key, -1) == 0)
		{
			lst_remove(env, iter.pos, free_content);
			return ;
		}
	}
}
