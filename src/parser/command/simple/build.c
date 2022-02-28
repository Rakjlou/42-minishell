/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/25 11:27:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

static int	valid_start(t_token *token)
{
	return (
		token_is_redirection_operator(token)
		|| token_is(token, TOK_TOKEN)
	);
}

static void	command_simple_build_recursive(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token	*token;

	token = iter->data;
	if (!valid_start(token))
		return ;
	else if (token_is_redirection_operator(token))
		command_redirection_build(
			parser,
			iter,
			command->data.simple.redirections
		);
}

void	command_simple_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_token		*token;

	token = iter->data;
	if (!valid_start(token))
		parser_unexpected_token(parser, token);
	else
		command_simple_build_recursive(parser, iter, command);
	/*
	** Recursion ?
	** build redirection
	** tout token generique est ajoute a la commande
	** tout token non generique est une syntax error ?
	*/
}
