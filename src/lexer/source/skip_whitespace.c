/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:15:00 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 20:57:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	lsource_skip_whitespace(t_lsource *src)
{
	while (ft_isspace(lsource_getc(src)))
		lsource_incr(src);
}
