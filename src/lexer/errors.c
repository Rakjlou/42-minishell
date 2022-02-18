/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:04:40 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 00:19:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftprintf.h"
#include "lexer/lexer.h"
#include "lexer/errors.h"

void	lexer_syntax_error(t_lexer *lexer, t_token *token, t_lexer_status e)
{
	char	*raw;

	lexer->status = e;
	raw = NULL;
	if (token != NULL)
		raw = token->raw;
	if (e == LEXER_UNEXPECTED_TOK_ERROR)
	{
		ftfprintf(
			STDERR_FILENO,
			"%s: syntax error near unexpected token `%s'\n",
			"minishell",
			raw);
	}
}
