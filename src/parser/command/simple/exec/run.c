/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 15:24:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static int	is_builtin(t_command *command)
{
	char	*candidate;
	char	*builtins[7];
	int		i;

	if (ft_cmatrix_size(command->argv) == 0)
		return (0);
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	candidate = command->argv[0];
	i = 0;
	while (i < 7)
	{
		if (!ft_strncmp(builtins[i], candidate, -1))
			return (1);
		++i;
	}
	return (0);
}

void	command_simple_run(t_command *command)
{
	if (command->status != 0 || !command_build_argv(command))
		return ;
	else if (is_builtin(command))
		builtin_exec(command);
	else
		command_exec(command);
}
