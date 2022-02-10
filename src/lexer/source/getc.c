/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:14:58 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:55:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/source.h"

char	source_getc(t_source *src)
{
	if (src->cursor >= src->size)
		return (SOURCE_EOF);
	return (src->raw[src->cursor]);
}
