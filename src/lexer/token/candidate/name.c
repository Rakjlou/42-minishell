/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:45:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer/token_candidate.h"

void	token_candidate_consume_name(t_token_candidate *candidate)
{
	char	c;

	token_candidate_incr(candidate);
	while (42)
	{
		c = source_getc(candidate->src);
		if (c != '_' && !ft_isalnum(c))
			return ;
		token_candidate_incr(candidate);
	}
}
