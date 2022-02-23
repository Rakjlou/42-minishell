/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:40:42 by ajung             #+#    #+#             */
/*   Updated: 2022/02/23 20:31:51 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
static int	create_new_elem(t_lst **ptr_list, char *key, char *value)
{
	t_lst			*new_elem;
	t_env_content	*new_content;

	new_elem = ft_calloc(sizeof(t_lst), 1);
	if (!new_elem)
		return (EXIT_FAILURE);
	new_content = ft_calloc(sizeof(t_env_content), 1);
	if (!new_content)
		return (free(new_elem), EXIT_FAILURE);
	new_content->key = ft_strdup(key);
	if (value != NULL)
		new_content->value = ft_strdup(value);
	if ((!new_content->value && value != NULL)|| !new_content->key)
		return (env_destroy_content(&new_content), free(new_elem), EXIT_FAILURE);
	new_elem->content = new_content;
	ft_lstadd_back(ptr_list, new_elem);
	return (EXIT_SUCCESS);
}

int		env_set_value(t_lst *env, char *key, char *value)
{
	t_env_content	*content;
	t_lst			*iter;

	iter = env;
	
	while (iter != NULL)
	{
		content = iter->content;
		if (ft_strncmp(content->key, key, -1) == 0)
			return (env_update_value(content, value));
		iter = iter->next;
	}
	create_new_elem(&env, key, value);

}
*/

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

static t_env_content	*env_content_new(char *key, char *value)
{
	t_env_content	*content;
	
	content = ft_calloc(sizeof(t_env_content), 1);
	if (!content)
		return (EXIT_FAILURE);
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

int		env_set_value(t_lst *env, char *key, char *value)
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
