/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:42:45 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:39:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	free_content(void *content)
{
	env_content_destroy(content);
}

void	env_free(void)
{
	lst_destroy_nodes(_env(), &free_content);
}
