/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:06:00 by ajung             #+#    #+#             */
/*   Updated: 2022/02/18 18:49:29 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

int		create_new_shell()
{
	int 	status;
	pid_t	process;
	
	ft_putstr_fd("Entering the abyss\n", 1);
	process = fork();
	waitpid(process, &status, 0);
	if (process < 0)
		return (perror("Fork: "), 1);
	else if (process > 0)
		write(1, "\n", 1);
	return (0);
	
}

void	test(char *input)
{
	if (ft_strncmp(input, "minishell", 9) == 0 && !input[9])
		create_new_shell();
}
