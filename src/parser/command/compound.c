/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:49:29 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

/*
** Une parenthèse ouvrante ne peut être que postionnée en première position,
** ou précédée d'un operateur logique ou d'un pipe
*/
static int	valid_start(t_command **command)
{
	return (
		command_is_empty(*command)
		|| command_is(*command, COMMAND_PIPELINE)
		|| command_is(*command, COMMAND_LIST)
	);
}

void	command_compound_run(t_command *command)
{
	t_command_compound	*compound_data;
	t_command			*after;
	t_command			*subshell;

	after = command->after;
	compound_data = &command->data.compound;
	subshell = compound_data->tree;
	exec_tree_dispatch(subshell);
	exec_tree_dispatch(after);
}

void	command_compound_debug(t_command *command, int level)
{
	t_command	*tree;

	tree = command->data.compound.tree;
	ftprintf("()\n");
	exec_tree_print(tree, level + 1);
}

void	command_compound_consume(t_parser *parser, t_iter *iter, t_command **c)
{
	t_command	*compound;

	if (!valid_start(c))
		return (parser_unexpected_token(parser, (t_token *)iter->data));
	compound = ft_calloc(sizeof(t_command), 1);
	if (compound == NULL)
		return (parser_internal_error(parser));
	compound->type = COMMAND_COMPOUND;
	compound->data.compound.tree = NULL;
	++parser->subshell;
	exec_tree_build_command(parser, iter, &compound->data.compound.tree);
	compound->before = *c;
	*c = compound;
}
