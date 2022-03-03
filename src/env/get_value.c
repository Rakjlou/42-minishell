/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:18:10 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:04:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*env_get_value(t_lst *env, char *key)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, env, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (ft_strncmp(content->key, key, -1) == 0)
			return (content->value);
	}
	return (NULL);
}
