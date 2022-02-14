/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:42:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 23:21:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "lexer/token_candidate.h"

/*
** If this minishell ever becomes a bigger shell, this will need to be
** generalized.
*/

int	token_candidate_is_part_of_operator(t_token_candidate *candidate)
{
	char	*text;
	int		result;
	size_t	len;

	if (candidate->quoting || !candidate->is_operator)
		return (0);
	text = token_candidate_text(candidate, 0, 1);
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

int	token_candidate_is_end_of_operator(t_token_candidate *candidate)
{
	char	*text;

	if (candidate->quoting || !candidate->is_operator)
		return (0);
	text = token_candidate_text(candidate, 0, 1);
	if (ft_strncmp(AND_IF, text, UINT_MAX) != 0
		&& ft_strncmp(OR_IF, text, UINT_MAX) != 0
		&& ft_strncmp(SLESS, text, UINT_MAX) != 0
		&& ft_strncmp(SGREAT, text, UINT_MAX) != 0
		&& ft_strncmp(DLESS, text, UINT_MAX) != 0
		&& ft_strncmp(DGREAT, text, UINT_MAX) != 0)
		return (free(text), --candidate->end, 1);
	return (free(text), 0);
}

int	token_candidate_is_start_of_operator(t_token_candidate *candidate)
{
	char	c;

	if (candidate->quoting || candidate->is_operator)
		return (0);
	c = source_getc(candidate->src);
	return (
		c == '&'
		|| c == '|'
		|| c == '<'
		|| c == '>'
	);
}
