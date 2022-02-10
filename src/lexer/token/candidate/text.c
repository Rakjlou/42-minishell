/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:43:40 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer/token_candidate.h"

char	*token_candidate_text(
	t_token_candidate *candidate,
	int start_offset,
	int len_offset)
{
	return (
		ft_substr(
			candidate->src->raw,
			(unsigned int)candidate->start + start_offset,
			candidate->end - candidate->start + len_offset
		)
	);
}
