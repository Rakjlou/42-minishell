/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:34:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:17:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "lexer/lexer.h"
#include "lexer/token.h"

void	lexer(char *line)
{
	t_source	src;
	t_token		*token;

	source_init(&src, line);
	while (42)
	{
		token = tokenize(&src);
		if (token == NULL)
			break ;
		else if (token_is_eof(token))
		{
			token_destroy(token);
			break ;
		}
		printf("\t%s\n", token->raw);
		token_destroy(token);
	}
}
