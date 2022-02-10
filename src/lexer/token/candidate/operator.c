/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:42:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:44:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!candidate->is_operator)
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

/* TODO: Bugfix "&&||&&" renvoie un seul token, probablement à cause de la
** naiveté de cette fonction... ou pas
*/
int	token_candidate_is_end_of_operator(t_token_candidate *candidate)
{
	char			c;

	if (!candidate->is_operator)
		return (0);
	c = source_getc(candidate->src);
	return (
		c != '&'
		&& c != '|'
		&& c != '<'
		&& c != '>'
	);
}

int	token_candidate_is_start_of_operator(t_token_candidate *candidate)
{
	char	c;

	if (candidate->is_operator)
		return (0);
	c = source_getc(candidate->src);
	return (
		c == '&'
		|| c == '|'
		|| c == '<'
		|| c == '>'
	);
}
