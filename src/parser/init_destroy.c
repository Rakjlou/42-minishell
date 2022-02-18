/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 18:52:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/parser.h"

static void	tree_destroy(t_command *command)
{
	t_command	*before;
	t_command	*after;

	if (command == NULL)
		return ;
	before = command->before;
	after = command->after;
	if (command->type == COMMAND_SIMPLE)
	{
		lst_destroy_nodes(&command->data.simple.redirections, free);
		lst_destroy_nodes(&command->data.simple.args, NULL);
	}
	free(command);
	tree_destroy(before);
	tree_destroy(after);
}

void	parser_init(t_parser *parser, char *line)
{
	ft_bzero(parser, sizeof(t_parser));
	lexer_init(&parser->lexer, line);
	lexer_build_token_list(&parser->lexer);
}

void	parser_destroy(t_parser *parser)
{
	lexer_destroy(&parser->lexer);
	tree_destroy(parser->tree);
	parser->tree = NULL;
}
