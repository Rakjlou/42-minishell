/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:44:48 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 22:12:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lexer/token.h"

void	token_destroy(t_token *token)
{
	free(token->raw);
	if (token->expanded != NULL)
		ft_cmatrix_free(token->expanded);
	free(token);
}

void	token_vdestroy(void *token)
{
	token_destroy((t_token *)token);
}
