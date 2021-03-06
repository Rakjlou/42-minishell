/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 18:28:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "handle_signal.h"

static void	param_init(int argc, char **argv)
{
	extern char	**environ;
	t_shell		*shell;

	shell = _shell();
	shell->param.argc = argc;
	shell->param.argv = argv;
	shell->param.env = environ;
	shell->pipeline.pipe_in = STDIN_FILENO;
	shell->pipeline.pipe_out = STDOUT_FILENO;
}

int	shell_init(int argc, char **argv)
{
	param_init(argc, argv);
	if ((env_init() != EXIT_SUCCESS)
		|| handle_signals(MAIN_PROCESS) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
