/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:35:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 23:52:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "lexer/token.h"
#include "lexer/tokens.h"

int	token_is_eof(t_token *token)
{
	return (token->src == NULL && token->raw == NULL && token->size == 0);
}

int	token_is(t_token *token, t_token_type type)
{
	return (token->type == type);
}

int	token_is_invalid_command_start(t_token *token)
{
	return (
		token_is(token, TOK_C_PARENTHESIS) || token_is(token, TOK_PIPE)
		|| token_is(token, TOK_AND_IF) || token_is(token, TOK_OR_IF)
	);
}

int	token_is_redirection_operator(t_token *token)
{
	return (
		token_is(token, TOK_DLESS) || token_is(token, TOK_DGREAT)
		|| token_is(token, TOK_SLESS) || token_is(token, TOK_SGREAT)
	);
}

int	token_is_operator(t_token *token)
{
	return (
		token_is_redirection_operator(token)
		|| token_is(token, TOK_AND_IF) || token_is(token, TOK_OR_IF)
		|| token_is(token, TOK_PIPE) || token_is(token, TOK_O_PARENTHESIS)
		|| token_is(token, TOK_C_PARENTHESIS)
	);
}
