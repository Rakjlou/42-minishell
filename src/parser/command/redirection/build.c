/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:38:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	command_redirection_build(t_parser *parser, t_iter *iter, t_lst *lst)
{
	t_redirection	candidate;
	t_redirection	*redirection;

	candidate.type = (t_token *)iter->data;
	if (!iter_next(iter))
		return (parser_unexpected_token(parser, NULL));
	candidate.arg = (t_token *)iter->data;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
		return (parser_internal_error(parser));
	redirection = ft_memcpy(redirection, &candidate, sizeof(t_redirection));
	if (!lst_push_back(lst, redirection))
		parser_internal_error(parser);
}
