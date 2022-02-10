/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:29:45 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:55:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lexer/token.h"
#include "libft.h"

t_token	*token_new(void)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	if (token == NULL)
		return (perror("minishell"), NULL);
	return (token);
}
