/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:23:14 by ajung             #+#    #+#             */
/*   Updated: 2022/02/21 16:31:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

void	init_arg_main(int argc, char **argv)
{
	t_shell 		*shell;
	extern char		**environ;

	shell = _shell();
	shell->args.argc = argc;
	shell->args.argv = argv;
	shell->args.env = environ;
}
