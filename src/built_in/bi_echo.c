/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:45:36 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 14:54:14 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	start_arg(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i] && arg[i][0] == '-' )
	{
		j = 1;
		while (arg[i][j])
		{
			if (arg[i][j] == 'n')
				j++;
			else
				return (i);
		}
		i++;
	}
	return (i);
}

int	bi_echo(char **arg)
{
	int	i;

	i = start_arg(arg);
	while (arg[i])
	{
		ft_putstr_fd(arg[i], STDOUT_FILENO);
		if (arg[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (start_arg(arg) == 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
