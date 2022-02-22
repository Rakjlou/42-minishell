/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/22 14:39:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_pipeline_build(t_parser *parser, t_iter *it, t_command **cmd)
{
	t_command	*pipeline;

	if (command_is_empty(*cmd))
		return (parser_unexpected_token(parser, (t_token *)it->data));
	pipeline = ft_calloc(sizeof(t_command), 1);
	if (pipeline == NULL)
		return (parser_internal_error(parser));
	pipeline->type = COMMAND_PIPELINE;
	pipeline->before = *cmd;
	exec_tree_build_recursive(parser, it, &pipeline->after);
	if (pipeline->after == NULL || command_is_empty(pipeline->after))
		parser_unexpected_token(parser, (t_token *)it->data);
	else
		*cmd = pipeline;
}
