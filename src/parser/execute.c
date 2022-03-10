/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:42:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 21:07:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	parser_execute(void)
{
	t_parser	*parser;

	parser = _parser();
	exec_tree_build(parser);
	if (parser->status == PARSER_STATUS_FINISHED)
	{
		exec_tree_print(parser->tree, 0);
		exec_tree_dispatch(parser->tree);
	}
	parser_destroy();
}
