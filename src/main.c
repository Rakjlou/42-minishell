/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 20:44:00 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

int	main(int argc, char **argv)
{
	if (shell_init(argc, argv) != EXIT_SUCCESS)
		return (perror("minishell"), EXIT_FAILURE);
	shell_loop();
	return (EXIT_SUCCESS);
}
