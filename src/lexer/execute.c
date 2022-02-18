/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:34:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/17 22:16:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "lexer/tokens.h"
#include "lexer/lexer.h"
#include "lexer/errors.h"

static int	classify_as_operator(t_token *token)
{
	if (!ft_strncmp(token->raw, AND_IF, UINT_MAX))
		token->type = TOK_AND_IF;
	else if (!ft_strncmp(token->raw, OR_IF, UINT_MAX))
		token->type = TOK_OR_IF;
	else if (!ft_strncmp(token->raw, DLESS, UINT_MAX))
		token->type = TOK_DLESS;
	else if (!ft_strncmp(token->raw, DGREAT, UINT_MAX))
		token->type = TOK_DGREAT;
	else
		return (0);
	return (1);
}

static int	classifier_single_operator_err(t_token *token)
{
	return (!ft_strncmp(token->raw, "&", UINT_MAX));
}

static void	lexer_spot_operators(t_lexer *lexer)
{
	t_iter	iter;
	t_token	*token;

	if (lexer->status != LEXER_STATUS_DEFAULT)
		return ;
	iter_init(&iter, &lexer->tokens, ASC);
	while (lexer->status == LEXER_STATUS_DEFAULT && iter_next(&iter))
	{
		token = (t_token *)iter.data;
		if (classifier_single_operator_err(token))
			lexer_syntax_error(lexer, token, LEXER_UNEXPECTED_TOK_ERROR);
		else if (!classify_as_operator(token))
			token->type = TOK_TOKEN;
	}
}

static void	lexer_load_tokens(t_lexer *lexer)
{
	t_token		*token;

	while (lexer->status == LEXER_STATUS_DEFAULT)
	{
		token = token_recognizer(&lexer->src);
		if (token == NULL)
			lexer->status = LEXER_STATUS_ERROR;
		else if (token->type == TOK_EOF)
		{
			token_destroy(token);
			break ;
		}
		else if (!lst_push_back(&lexer->tokens, token))
		{
			lexer->status = LEXER_STATUS_ERROR;
			perror("minishell");
		}
	}
}

void	lexer_execute(char *line)
{
	t_lexer		lexer;

	lexer_init(&lexer, line);
	lexer_load_tokens(&lexer);
	lexer_spot_operators(&lexer);
	lexer_destroy(&lexer);
}
