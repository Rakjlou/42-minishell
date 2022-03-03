/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 22:28:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "parser/parser.h"

void	command_list_run(t_command *command)
{
	t_command_list	*list_data;
	t_command		*before;
	t_command		*after;

	before = command->before;
	after = command->after;
	list_data = &command->data.list;
	if (token_is(list_data->type, TOK_AND_IF))
	{
		exec_tree_dispatch(before);
		if (before->status == EXIT_SUCCESS)
			exec_tree_dispatch(after);
	}
	else if (token_is(list_data->type, TOK_OR_IF))
	{
		exec_tree_dispatch(before);
		if (before->status != EXIT_SUCCESS)
			exec_tree_dispatch(after);
	}
	else
		ftfprintf(STDERR_FILENO,
			E_INVALID_LIST_TOKEN_TYPE,
			"minishell",
			list_data->type->raw);
}
