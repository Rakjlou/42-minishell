/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/25 11:39:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	command_redirection_build(t_parser *parser, t_iter *iter, t_lst *lst)
{
	t_token			*token;
	t_redirection	*redirection;
	t_redirection	candidate;

	candidate.type = iter->data;
	if (!iter_next(iter))
		return (parser_unexpected_token(parser, NULL));
	else if (!token_is(iter->data, TOK_TOKEN))
		return (parser_unexpected_token(parser, iter->data));
	token = iter->data;
	token->type = TOK_WORD;
	candidate.arg = token;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
		return (parser_internal_error(parser));
	redirection = ft_memcpy(redirection, &candidate, sizeof(t_redirection));
	if (!lst_push_back(lst, redirection))
		parser_internal_error(parser);
}
