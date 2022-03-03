/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:18:10 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:27:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_content	*env_get_content(char *key)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, _env(), ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (ft_strncmp(content->key, key, -1) == 0)
			return (content);
	}
	return (NULL);
}

char	*env_get_value(char *key)
{
	t_env_content	*content;

	content = env_get_content(key);
	if (content == NULL)
		return (NULL);
	return (content->value);
}
