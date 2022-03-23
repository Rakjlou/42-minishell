/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 18:59:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "shell.h"

static void	param_init(int argc, char **argv)
{
	extern char	**environ;
	t_shell		*shell;

	shell = _shell();
	shell->param.argc = argc;
	shell->param.argv = argv;
	shell->param.env = environ;
	//shell->exec.pipe_in = STDIN_FILENO;
	//shell->exec.pipe_out = STDOUT_FILENO;
}

int	shell_init(int argc, char **argv)
{
	param_init(argc, argv);
	if ((env_init() != EXIT_SUCCESS) || signals_init() != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
