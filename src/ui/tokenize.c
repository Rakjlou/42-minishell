/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:44:38 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 00:33:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "user_input.h"
#include "libft.h"

static t_token	*token_new(void)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	if (token == NULL)
		return (perror(UI_TOK_ALLOC_E), NULL);
	return (token);
}

t_token	*ui_tokenize(t_user_input *ui)
{
	char			c;
	t_token			*token;
	unsigned long	start;
	unsigned long	end;

	token = token_new();
	if (token == NULL)
		return (NULL);
	ui_skip_whitespace(ui);
	start = ui->cursor;
	while (42)
	{
		c = ui_peek(ui);
		if (c == UI_EOF || ft_isspace(c))
			break ;
		ui_next(ui);
	}
	end = ui->cursor;
	if (start == end)
		return (token);
	token->raw = ft_substr(ui->raw, (unsigned int)start, end - start);
	if (token->raw == NULL)
		return (perror(UI_TOK_TEXT_ALLOC_E), token);
	token->size = end - start;
	return (token->ui = ui, token);
}
