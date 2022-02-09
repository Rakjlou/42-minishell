/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:35:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:29:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lexer.h"

int	ltoken_is_eof(t_ltoken *token)
{
	return (token->ui == NULL && token->raw == NULL && token->size == 0);
}