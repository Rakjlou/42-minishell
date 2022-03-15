/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/15 18:43:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static void	set_parent(t_command *list)
{
	if (list->before != NULL)
		list->before->parent = list;
	if (list->after != NULL)
		list->after->parent = list;
}

void	command_list_build(t_parser *parser, t_iter *iter, t_command **command)
{
	t_command	*list;

	if (command_is_empty(*command))
		return (parser_unexpected_token(parser, (t_token *)iter->data));
	list = ft_calloc(sizeof(t_command), 1);
	if (list == NULL)
		return (parser_internal_error(parser));
	list->type = COMMAND_LIST;
	list->data.list.type = (t_token *)iter->data;
	list->before = *command;
	parser_next_token(parser, iter);
	exec_tree_build_recursive(parser, iter, &list->after);
	*command = list;
	if (list->after == NULL || command_is_empty(list->after))
		parser_unexpected_token(parser, (t_token *)iter->data);
	set_parent(list);
}
