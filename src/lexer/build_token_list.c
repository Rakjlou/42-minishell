/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:34:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 21:01:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"
#include "lexer/tokens.h"
#include "lexer/lexer.h"
#include "lexer/errors.h"

static int	classify_as_operator(t_token *token)
{
	if (!ft_strncmp(token->raw, AND_IF, -1))
		token->type = TOK_AND_IF;
	else if (!ft_strncmp(token->raw, OR_IF, -1))
		token->type = TOK_OR_IF;
	else if (!ft_strncmp(token->raw, DLESS, -1))
		token->type = TOK_DLESS;
	else if (!ft_strncmp(token->raw, DGREAT, -1))
		token->type = TOK_DGREAT;
	else if (!ft_strncmp(token->raw, SLESS, -1))
		token->type = TOK_SLESS;
	else if (!ft_strncmp(token->raw, SGREAT, -1))
		token->type = TOK_SGREAT;
	else if (!ft_strncmp(token->raw, O_PARENTHESIS, -1))
		token->type = TOK_O_PARENTHESIS;
	else if (!ft_strncmp(token->raw, C_PARENTHESIS, -1))
		token->type = TOK_C_PARENTHESIS;
	else if (!ft_strncmp(token->raw, PIPE, -1))
		token->type = TOK_PIPE;
	else
		return (0);
	return (1);
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
		if (!classify_as_operator(token))
			token->type = TOK_TOKEN;
		if (LEXER_DEBUG)
			printf("%-2d | %s\n", token->type, token->raw);
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
		else if (token_is(token, TOK_EOF))
		{
			token_destroy(token);
			break ;
		}
		else if (!lst_push_back(&lexer->tokens, token))
		{
			lexer->status = LEXER_STATUS_ERROR;
			token_destroy(token);
			perror("minishell");
		}
	}
}

void	lexer_build_token_list(t_lexer *lexer)
{
	lexer_load_tokens(lexer);
	lexer_spot_operators(lexer);
}
