/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:44:38 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:21:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "lexer.h"
#include "libft.h"

static t_ltoken	*ltoken_categorize(t_ltoken *token)
{
	token->type = LTOK_TOKEN;
	return (token);
}

static void	ltoken_candidate_init(t_lsource *src, t_ltoken_candidate *candidate)
{
	ft_bzero(candidate, sizeof(t_ltoken_candidate));
	candidate->src = src;
	candidate->start = src->cursor;
	candidate->end = candidate->start;
}

static void	ltoken_candidate_incr(t_ltoken_candidate *candidate)
{
	lsource_incr(candidate->src);
	candidate->end = candidate->src->cursor;
}

static char	*ltoken_candidate_text(
	t_ltoken_candidate *candidate,
	int start_offset,
	int len_offset)
{
	return (
		ft_substr(
			candidate->src->raw,
			(unsigned int)candidate->start + start_offset,
			candidate->end - candidate->start + len_offset
		)
	);
}

/*
** If this minishell ever becomes a bigger shell, this will need to be
** generalized.
*/
static int	ltoken_candidate_is_part_of_operator(t_ltoken_candidate *candidate)
{
	char	*text;
	int		result;
	size_t	len;

	if (!candidate->is_operator)
		return (0);
	text = ltoken_candidate_text(candidate, 0, 1);
	if (text == NULL)
		return (perror("minishell"), 0);
	len = ft_strlen(text);
	result = (ft_strncmp(text, AND_IF, len) == 0
			|| ft_strncmp(text, OR_IF, len) == 0
			|| ft_strncmp(text, DLESS, len) == 0
			|| ft_strncmp(text, DGREAT, len) == 0);
	free(text);
	return (result);
}

static int	ltoken_candidate_is_end_of_operator(t_ltoken_candidate *candidate)
{
	char	c;

	if (!candidate->is_operator)
		return (0);
	c = lsource_getc(candidate->src);
	return (
		c != '&'
		&& c != '|'
		&& c != '<'
		&& c != '>'
	);
}

static int	ltoken_candidate_is_start_of_operator(t_ltoken_candidate *candidate)
{
	char	c;

	if (candidate->is_operator)
		return (0);
	c = lsource_getc(candidate->src);
	return (
		c == '&'
		|| c == '|'
		|| c == '<'
		|| c == '>'
	);
}

static int	ltoken_candidate_is_quote(t_ltoken_candidate *candidate)
{
	char	c;

	c = lsource_getc(candidate->src);
	return (c == '\'' || c == '"');
}

static int	ltoken_candidate_is_unquoted_param(t_ltoken_candidate *candidate)
{
	return (!candidate->quote && lsource_getc(candidate->src) == '$');
}

static int	ltoken_candidate_is_unquoted_space(t_ltoken_candidate *candidate)
{
	return (!candidate->quote && ft_isspace(lsource_getc(candidate->src)));
}

/* TODO: Refacto pour supporter l'état général du lexer. Structure lexer ?
** Ici quand c == LEX_EOF && quoting, une erreur doit se produire
*/
/*static void	ltoken_candidate_consume_quote(t_ltoken_candidate *candidate)
{
	char	c;
	char	quote;
	int		quoting;

	quote = lsource_getc(candidate->src);
	quoting = 1;
	ltoken_candidate_incr(candidate);
	while (42)
	{
		c = lsource_getc(candidate->src);
		if (c == quote)
			quoting = !quoting;
		else if (quoting && c == LEX_EOF)
			return ;
		else if (!quoting && (c == LEX_EOF || ft_isspace(c)))
			return ;
		ltoken_candidate_incr(candidate);
	}
}*/

static void	ltoken_candidate_handle_quote(t_ltoken_candidate *candidate)
{
	if (candidate->quoting && lsource_getc(candidate->src) == candidate->quote)
		candidate->quoting = 0;
	else if (!candidate->quoting)
	{
		candidate->quoting = 1;
		candidate->quote = lsource_getc(candidate->src);
	}
	ltoken_candidate_incr(candidate);
}

/* TODO: POSIX demande d'interdire les names commençant par un digit,
** ici c'est autorisé
*/
static void	ltoken_candidate_consume_name(t_ltoken_candidate *candidate)
{
	char	c;

	ltoken_candidate_incr(candidate);
	while (42)
	{
		c = lsource_getc(candidate->src);
		if (c != '_' && !ft_isalnum(c))
			return ;
		ltoken_candidate_incr(candidate);
	}
}

static void	consume_source(t_lsource *src)
{
	t_ltoken_candidate	token;

	ltoken_candidate_init(src, &token);
	while (!token.delimited)
	{
		if (lsource_getc(token.src) == LEX_EOF)
			token.delimited = 1;
		else if (ltoken_candidate_is_part_of_operator(&token))
			ltoken_candidate_incr(&token);
		else if (ltoken_candidate_is_end_of_operator(&token))
			token.delimited = 1;
		else if (ltoken_candidate_is_quote(&token))
			ltoken_candidate_handle_quote(&token);
		else if (ltoken_candidate_is_unquoted_param(&token))
			ltoken_candidate_consume_name(&token);
		else if (ltoken_candidate_is_start_of_operator(&token) && token.end != token.start)
			token.delimited = 1;
		else if (ltoken_candidate_is_start_of_operator(&token))
			(token.is_operator = 1, ltoken_candidate_incr(&token));
		else if (ltoken_candidate_is_unquoted_space(&token))
			token.delimited = 1;
		else if (token.is_word)
			ltoken_candidate_incr(&token);
		else
			(token.is_word = 1, ltoken_candidate_incr(&token));
	}
}

t_ltoken	*ltokenize(t_lsource *src)
{
	t_ltoken		*token;
	unsigned long	start;
	unsigned long	end;

	token = ltoken_new();
	if (token == NULL)
		return (NULL);
	lsource_skip_whitespace(src);
	start = src->cursor;
	consume_source(src);
	end = src->cursor;
	if (start == end)
		return (token);
	token->raw = ft_substr(src->raw, (unsigned int)start, end - start);
	if (token->raw == NULL)
		return (perror(LEX_TOK_TEXT_ALLOC_E), token);
	token->size = end - start;
	return (token->src = src, ltoken_categorize(token));
}
