/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:40:42 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:37:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	env_update_value(t_env_content *content, char *value)
{
	if (value == NULL)
		return (EXIT_SUCCESS);
	else if (content->value != NULL)
		free(content->value);
	content->value = ft_strdup(value);
	if (content->value == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_env_content	*env_content_new(char *key, char *value)
{
	t_env_content	*content;

	content = ft_calloc(sizeof(t_env_content), 1);
	if (!content)
		return (NULL);
	content->key = ft_strdup(key);
	if (!content->key)
		return (env_content_destroy(content), NULL);
	else if (value != NULL)
	{
		content->value = ft_strdup(value);
		if (!content->value)
			return (env_content_destroy(content), NULL);
	}
	return (content);
}

static int	create_new_elem(t_lst *env, char *key, char *value)
{
	t_env_content	*content;

	content = env_content_new(key, value);
	if (!content || lst_push_back(env, content) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	env_set_value(t_lst *env, char *key, char *value)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, env, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (ft_strncmp(content->key, key, -1) == 0)
			return (env_update_value(content, value));
	}
	return (create_new_elem(env, key, value));
}
