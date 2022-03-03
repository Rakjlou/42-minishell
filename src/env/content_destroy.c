/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:16:09 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:36:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_content_destroy(t_env_content *content)
{
	free(content->value);
	free(content->key);
	free(content);
}
