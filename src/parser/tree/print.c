/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:26 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/21 21:21:51 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

static void	tree_print_repeatc(unsigned char c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n)
		ft_putchar_fd(c, STDOUT_FILENO);
}

static void	tree_print_command(t_command *command, int level)
{
	if (command->type == COMMAND_SIMPLE)
		command_simple_debug(command);
	else if (command->type == COMMAND_LIST)
		command_list_debug(command);
	else if (command->type == COMMAND_PIPELINE)
		command_pipeline_debug(command);
	else if (command->type == COMMAND_COMPOUND)
		command_compound_debug(command, level);
	else
		ftprintf("Unknown\n");
}

void	exec_tree_print(t_command *tree, int level)
{
	if (tree == NULL || !PARSER_DEBUG)
		return ;
	tree_print_repeatc(' ', level * 4);
	tree_print_command(tree, level);
	++level;
	exec_tree_print(tree->before, level);
	exec_tree_print(tree->after, level);
}

/*
** TODO: REMOVE ME
*/
void	print_wordexp(t_token *token)
{
	char	**words;
	int		i;

	if (token == NULL)
		return ;
	i = 0;
	words = ft_wordexp(token->raw);
	while (words && words[i] != NULL)
	{
		ftfprintf(STDERR_FILENO, "%s ", words[i]);
		i++;
	}

}
