/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:11 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:40:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer/token_candidate.h"

void	token_candidate_init(t_source *src, t_token_candidate *candidate)
{
	ft_bzero(candidate, sizeof(t_token_candidate));
	candidate->src = src;
	candidate->start = src->cursor;
	candidate->end = candidate->start;
}
