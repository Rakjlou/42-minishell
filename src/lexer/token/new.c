/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:29:45 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:31:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lexer.h"
#include "libft.h"

t_ltoken	*ltoken_new(void)
{
	t_ltoken	*token;

	token = ft_calloc(sizeof(t_ltoken), 1);
	if (token == NULL)
		return (perror(LEX_TOK_ALLOC_E), NULL);
	return (token);
}
