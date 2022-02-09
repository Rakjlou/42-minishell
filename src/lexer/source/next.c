/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:14:58 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:31:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	lsource_next(t_lsource *src)
{
	if (src->cursor >= src->size)
		return (LEX_EOF);
	return (src->raw[src->cursor++]);
}
