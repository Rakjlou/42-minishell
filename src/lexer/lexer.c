/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:34:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/11 02:45:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lexer/tokens.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "ftprintf.h"
#include "lexer/lexer.h"

static void	lexer_init(t_lexer *lexer, char *line)
{
	ft_bzero(lexer, sizeof(t_lexer));
	source_init(&lexer->src, line);
}

static void	lexer_destroy(t_lexer *lexer)
{
	lst_destroy_nodes(&lexer->tokens, token_vdestroy);
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

static void lexer_syntax_error(t_lexer *lexer, t_token *token, t_lexer_status e)
{
	lexer->status = e;
	if (e == LEXER_UNEXPECTED_TOK_ERROR)
	{
		ftfprintf(
			STDERR_FILENO,
			"%s: syntax error near unexpected token `%s'\n",
			"minishell",
			token->raw);
	}
}

static int	classifier_single_operator_err(t_token *token)
{
	return (!ft_strncmp(token->raw, "&", UINT_MAX));
}

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

static void	lexer_params_classify(t_lexer *lexer)
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
		else if (classify_as_operator(token))
		{
			printf("TOKEN %s TYPE %d\n", token->raw, token->type);
			continue ;
		}
		else
			token->type = TOK_TOKEN;
		printf("TOKEN %s TYPE %d\n", token->raw, token->type);
	}
}

void	lexer_execute(char *line)
{
	t_lexer		lexer;

	lexer_init(&lexer, line);
	lexer_load_tokens(&lexer);
	lexer_params_classify(&lexer);
	lexer_destroy(&lexer);
}
