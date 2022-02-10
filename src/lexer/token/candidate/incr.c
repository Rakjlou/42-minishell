/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:37:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/token_candidate.h"

void	token_candidate_incr(t_token_candidate *candidate)
{
	source_incr(candidate->src);
	candidate->end = candidate->src->cursor;
}
