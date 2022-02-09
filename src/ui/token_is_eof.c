/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_is_eof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:35:51 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 00:37:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "user_input.h"

int	ui_token_is_eof(t_token *token)
{
	return (token->ui == NULL && token->raw == NULL && token->size == 0);
}
