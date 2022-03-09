/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:14:58 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 17:07:15 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/source.h"

char	source_getc(t_source *src)
{
	if (src->cursor >= src->size)
		return (SOURCE_EOF);
	return (src->raw[src->cursor]);
}
