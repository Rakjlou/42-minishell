/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 19:14:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "ft_wordexp.h"
#include "parser/parser.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	wordexp_debug(char *str, ...)
{
	va_list	args;

	if (WORDEXP_DEBUG == 0)
		return ;
	va_start(args, str);
	vdprintf(STDERR_FILENO, str, args);
}

/*
** TODO: REMOVE ME
*/
void	print_wordexp(t_token *token)
{
	char	**words;
	int		i;

	if (token == NULL || WORDEXP_DEBUG == 0)
		return ;
	words = ft_wordexp(token->raw);
	i = 0;
	while (words && words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}
