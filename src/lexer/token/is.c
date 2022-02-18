/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:35:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 19:00:21 by nsierra-         ###   ########.fr       */
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

int	token_is_logical_operator(t_token *token)
{
	return (
		token->type == TOK_AND_IF
		|| token->type == TOK_OR_IF
	);
}

int	token_is_pipeline(t_token *token)
{
	return (!ft_strncmp(token->raw, PIPE, -1));
}

int	token_is_redirection_operator(t_token *token)
{
	return (
		token->type == TOK_DLESS
		|| token->type == TOK_DGREAT
		|| !ft_strncmp(token->raw, SLESS, -1)
		|| !ft_strncmp(token->raw, SGREAT, -1)
	);
}
