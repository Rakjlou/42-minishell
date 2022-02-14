/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:44:38 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/11 01:29:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "lexer/token_candidate.h"
#include "lexer/token.h"
#include "libft.h"

static void	consume_source(t_source *src)
{
	t_token_candidate	token;

	token_candidate_init(src, &token);
	while (!token.delimited)
		if (source_getc(token.src) == SOURCE_EOF)
		token.delimited = 1;
	else if (token_candidate_is_part_of_operator(&token))
		token_candidate_incr(&token);
	else if (token_candidate_is_end_of_operator(&token))
		token.delimited = 1;
	else if (token_candidate_is_quote(&token))
		token_candidate_handle_quote(&token);
	else if (token_candidate_is_unquoted_param(&token))
		token_candidate_consume_name(&token);
	else if (token_candidate_is_start_of_operator(&token)
		&& token.end != token.start)
		token.delimited = 1;
	else if (token_candidate_is_start_of_operator(&token))
		token.is_operator = 1;
	else if (token_candidate_is_unquoted_space(&token))
		token.delimited = 1;
	else if (token.is_word)
		token_candidate_incr(&token);
	else
		(token_candidate_incr(&token), token.is_word = 1);
}

t_token	*token_recognizer(t_source *src)
{
	t_token			*token;
	unsigned long	start;
	unsigned long	end;

	token = token_new();
	if (token == NULL)
		return (NULL);
	source_skip_whitespace(src);
	start = src->cursor;
	consume_source(src);
	end = src->cursor;
	if (start == end)
		return (token);
	token->raw = ft_substr(src->raw, (unsigned int)start, end - start);
	if (token->raw == NULL)
		return (perror("minishell"), token);
	token->size = end - start;
	token->src = src;
	token->type = TOK_TOKEN;
	return (token);
}
