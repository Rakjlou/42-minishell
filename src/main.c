/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 20:11:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

int	main(int argc, char **argv)
{
	if (shell_init(argc, argv) != EXIT_SUCCESS)
		return (perror("minishell"), shell_destroy(), EXIT_FAILURE);
	shell_loop();
	shell_destroy();
	return (_last_command_status());
}
