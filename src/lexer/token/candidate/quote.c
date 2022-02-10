/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:41:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer/token_candidate.h"

int	token_candidate_is_quote(t_token_candidate *candidate)
{
	char	c;

	c = source_getc(candidate->src);
	return (c == '\'' || c == '"');
}

int	token_candidate_is_unquoted_param(t_token_candidate *candidate)
{
	return (!candidate->quoting && source_getc(candidate->src) == '$');
}

int	token_candidate_is_unquoted_space(t_token_candidate *candidate)
{
	return (!candidate->quoting && ft_isspace(source_getc(candidate->src)));
}

void	token_candidate_handle_quote(t_token_candidate *candidate)
{
	if (candidate->quoting && source_getc(candidate->src) == candidate->quote)
		candidate->quoting = 0;
	else if (!candidate->quoting)
	{
		candidate->quoting = 1;
		candidate->quote = source_getc(candidate->src);
	}
	token_candidate_incr(candidate);
}
