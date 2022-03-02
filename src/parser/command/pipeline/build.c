/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:25:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

void	command_pipeline_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_command	*pipeline;

	if (command_is_empty(*command))
		return (parser_unexpected_token(parser, (t_token *)iter->data));
	pipeline = ft_calloc(sizeof(t_command), 1);
	if (pipeline == NULL)
		return (parser_internal_error(parser));
	pipeline->type = COMMAND_PIPELINE;
	pipeline->before = *command;
	parser_next_token(parser, iter);
	exec_tree_build_recursive(parser, iter, &pipeline->after);
	*command = pipeline;
	if (pipeline->after == NULL || command_is_empty(pipeline->after))
		parser_unexpected_token(parser, (t_token *)iter->data);
}
