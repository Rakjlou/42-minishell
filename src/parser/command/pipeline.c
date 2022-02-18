/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 19:04:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_pipeline_debug(t_command *command)
{
	(void)command;
	ftprintf("|\n");
}

void	command_pipeline_consume(t_parser *parser, t_iter *it, t_command **cmd)
{
	t_command	*pipeline;

	if (*cmd == NULL || command_is_empty(*cmd))
		parser_unexpected_token(parser, (t_token *)it->data);
	pipeline = ft_calloc(sizeof(t_command), 1);
	if (pipeline == NULL)
		parser_internal_error(parser);
	pipeline->type = COMMAND_PIPELINE;
	pipeline->before = *cmd;
	parser_tree_build_command(parser, it, &pipeline->after);
	if (pipeline->after == NULL || command_is_empty(pipeline->after))
		parser_unexpected_token(parser, (t_token *)it->data);
	else
		*cmd = pipeline;
}
