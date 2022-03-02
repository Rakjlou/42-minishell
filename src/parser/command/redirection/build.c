/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:30:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "input.h"
#include "parser/parser.h"

void	redirection_build(t_parser *parser, t_iter *iter, t_lst *lst)
{
	t_token			*type;
	t_token			*arg;
	t_redirection	*redirection;

	type = iter->data;
	if (!parser_next_token_noendl(parser, iter))
		return ;
	else if (!token_is(iter->data, TOK_TOKEN))
		return (parser_unexpected_token(parser, iter->data));
	arg = iter->data;
	arg->type = TOK_WORD;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
		return (parser_internal_error(parser));
	redirection->type = type;
	redirection->arg = arg;
	if (!lst_push_back(lst, redirection))
		parser_internal_error(parser);
	else if (token_is(redirection->type, TOK_DLESS))
		heredoc_request(parser, redirection);
	parser_next_token(parser, iter);
}
