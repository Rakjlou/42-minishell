/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:17:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:55:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer/source.h"

void	source_init(t_source *src, char *raw)
{
	ft_bzero(src, sizeof(t_source));
	src->raw = raw;
	src->size = (unsigned long)ft_strlen(raw);
	src->cursor = 0;
}
