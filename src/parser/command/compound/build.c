/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/28 21:45:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	command_compound_build(
	t_parser *parser,
	t_iter *iter,
	t_command **command)
{
	t_command			*compound;
	t_command_compound	*cdata;

	if (!valid_start(command))
		return (parser_unexpected_token(parser, (t_token *)iter->data));
	compound = ft_calloc(sizeof(t_command), 1);
	if (compound == NULL)
		return (parser_internal_error(parser));
	compound->type = COMMAND_COMPOUND;
	cdata = &compound->data.compound;
	cdata->tree = NULL;
	++parser->subshell;
	if (!parser_next_token_noendl(parser, iter))
		return ;
	exec_tree_build_recursive(parser, iter, &cdata->tree);
	--parser->subshell;
	if (!token_is(iter->data, TOK_C_PARENTHESIS))
		return (parser_unexpected_token(parser, iter->data));
	compound->before = *command;
	*command = compound;
	if (!parser_next_token(parser, iter))
		return ;
	while (token_is_redirection_operator(iter->data))
		command_redirection_build(parser, iter, &cdata->redirections);
}
