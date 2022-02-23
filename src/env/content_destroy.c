/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:16:09 by ajung             #+#    #+#             */
/*   Updated: 2022/02/23 20:32:17 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_content_destroy(t_env_content *content)
{
	free(content->value);
	free(content->key);
	free(content);
}
