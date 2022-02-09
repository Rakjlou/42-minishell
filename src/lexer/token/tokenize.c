/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:44:38 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:31:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lexer.h"
#include "libft.h"

t_ltoken	*ltokenize(t_lsource *ui)
{
	char			c;
	t_ltoken		*token;
	unsigned long	start;
	unsigned long	end;

	token = ltoken_new();
	if (token == NULL)
		return (NULL);
	lsource_skip_whitespace(ui);
	start = ui->cursor;
	while (42)
	{
		c = lsource_peek(ui);
		if (c == LEX_EOF || ft_isspace(c))
			break ;
		lsource_next(ui);
	}
	end = ui->cursor;
	if (start == end)
		return (token);
	token->raw = ft_substr(ui->raw, (unsigned int)start, end - start);
	if (token->raw == NULL)
		return (perror(LEX_TOK_TEXT_ALLOC_E), token);
	token->size = end - start;
	return (token->ui = ui, token);
}
