/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:59:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_simple_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	token = (t_token *)iter->data;
	/*
	** Recursion ?
	** build redirection
	** tout token generique est ajoute a la commande
	** tout token non generique est une syntax error ?
	*/
}
