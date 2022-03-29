/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:40:42 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 20:54:19 by nsierra-         ###   ########.fr       */
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

static int	create_new_elem(char *key, char *value)
{
	t_env_content	*content;

	content = env_content_new(key, value);
	if (content == NULL)
		return (EXIT_FAILURE);
	else if (!lst_push_back(_env(), content))
		return (env_content_destroy(content), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	env_set_value(char *key, char *value)
{
	t_env_content	*content;

	content = env_get_content(key);
	if (content == NULL)
		return (create_new_elem(key, value));
	return (env_update_value(content, value));
}
