/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 20:43:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

int	parser_next_token(t_parser *parser, t_iter *iter)
{
	if (!iter_next(iter))
	{
		if (parser->subshell > 0)
			parser_unexpected_token(parser, NULL);
		else
			parser->status = PARSER_STATUS_FINISHED;
		return (0);
	}
	return (1);
}

int	parser_next_token_noendl(t_parser *parser, t_iter *iter)
{
	if (!iter_next(iter))
		return (parser_unexpected_token(parser, NULL), 0);
	return (1);
}
