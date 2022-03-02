/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:06:29 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/17 22:10:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/lexer.h"

void	lexer_init(t_lexer *lexer, char *line)
{
	ft_bzero(lexer, sizeof(t_lexer));
	source_init(&lexer->src, line);
}

void	lexer_destroy(t_lexer *lexer)
{
	lst_destroy_nodes(&lexer->tokens, token_vdestroy);
}
