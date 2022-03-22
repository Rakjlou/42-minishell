/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/22 20:16:37 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static int	is_builtin(char *str)
{
	char	*builtins[7];
	int		i;

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	i = 0;
	while (i < 7)
	{
		if (!ft_strncmp(builtins[i], str, -1))
			return (1);
		++i;
	}
	return (0);
}

void	command_simple_run(t_command *command)
{
	if (command->status != 0
		|| !command_build_argv(command)
		|| ft_cmatrix_size(command->argv) == 0)
		return ;
	else if (is_builtin(command->argv[0]))
		builtin_exec(command);
	else
		command_exec(command);
}
