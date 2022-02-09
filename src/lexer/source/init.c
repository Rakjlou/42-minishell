/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:17:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:25:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	lsource_init(t_lsource *src, char *raw)
{
	ft_bzero(src, sizeof(t_lsource));
	src->raw = raw;
	src->size = (unsigned long)ft_strlen(raw);
	src->cursor = 0;
}
