/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/21 20:20:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ftprintf.h"

void	subshell_start(t_command *subshell)
{
	t_exec	exec_save;

	ft_memcpy(&exec_save, &_shell()->exec, sizeof(t_exec));
	_shell()->exec.pipeline = 0;
	exec_tree_run(subshell);
	ft_memcpy(&_shell()->exec, &exec_save, sizeof(t_exec));
}

void	command_compound_run(t_command *command)
{
	t_command_compound	*compound_data;
	t_command			*subshell;

	compound_data = &command->data.compound;
	subshell = compound_data->tree;
	subshell_start(subshell);
}
