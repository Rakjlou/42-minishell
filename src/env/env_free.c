/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:42:45 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:33:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	free_content(void *content)
{
	env_content_destroy((t_env_content *)content);
}

void	env_free(t_lst *env)
{
	lst_destroy_nodes(env, &free_content);
}
