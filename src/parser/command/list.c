/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 20:17:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_list_debug(t_command *command)
{
	ftprintf("%s\n", (char *)command->data.list.type->raw);
}

void	command_list_consume(t_parser *parser, t_iter *iter, t_command **cmd)
{
	t_command	*list;

	if (*cmd == NULL || command_is_empty(*cmd))
	{
		parser_unexpected_token(parser, (t_token *)iter->data);
		return ;
	}
	list = ft_calloc(sizeof(t_command), 1);
	if (list == NULL)
		parser_internal_error(parser);
	list->type = COMMAND_LIST;
	list->data.list.type = (t_token *)iter->data;
	list->before = *cmd;
	parser_tree_build_command(parser, iter, &list->after);
	if (list->after == NULL || command_is_empty(list->after))
		parser_unexpected_token(parser, (t_token *)iter->data);
	else
		*cmd = list;
}
