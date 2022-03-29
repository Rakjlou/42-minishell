/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:16:09 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 22:40:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_content_destroy(t_env_content *content)
{
	free(content->value);
	free(content->key);
	free(content);
}

t_env_content	*env_content_new(char *key, char *value)
{
	t_env_content	*content;

	content = ft_calloc(sizeof(t_env_content), 1);
	if (!content || !key)
		return (free(content), NULL);
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
