/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:47:14 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:37:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_print(t_lst *env)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, env, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (content->value == NULL)
			continue ;
		ftprintf("%s=%s\n", content->key, content->value);
	}
}

static int	get_copy_env(t_lst *env, t_lst *copy)
{
	t_iter			iter;
	t_env_content	*content;

	iter_init(&iter, env, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (lst_push_back(copy, content) == 0)
			return (lst_destroy_nodes(copy, NULL), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	compare_key(void *node1, void *node2)
{
	t_env_content	*content1;
	t_env_content	*content2;

	content1 = (t_env_content *)node1;
	content2 = (t_env_content *)node2;
	return (ft_strncmp(content1->key, content2->key, -1));
}

void	env_print_export(t_lst *env)
{
	t_iter			iter;
	t_env_content	*content;
	t_lst			copy;

	ft_bzero(&copy, sizeof(t_lst));
	if (get_copy_env(env, &copy) == EXIT_FAILURE)
		return (perror("minishell"));
	lst_bubble_sort(&copy, &compare_key);
	iter_init(&iter, &copy, ASC);
	while (iter_next(&iter))
	{
		content = iter.data;
		if (content->value == NULL)
			ftprintf("export %s\n", content->key);
		else
			ftprintf("export %s=\"%s\"\n", content->key, content->value);
	}
	lst_destroy_nodes(&copy, NULL);
	return ;
}
