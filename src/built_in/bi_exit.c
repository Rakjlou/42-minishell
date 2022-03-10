/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:41:03 by ajung             #+#    #+#             */
/*   Updated: 2022/03/09 21:04:24 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "shell.h"
#include "libft/libft.h"
#include "libft/ftprintf.h"
#include <input.h>

static void	too_many_args(char **arg)
{
	ftfprintf(STDERR_FILENO, "%s: %s: %s\n",
				"minishell",
				arg[0],
				"too many arguments");
}

static void non_numeric_args(char **arg)
{
	ftfprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
			"minishell",
			arg[0],
			arg[1],
			"numeric argument required");
	input_clear();
	env_free();
	exit(2);
	
}

static void	valid_exit_no_arg()
{
	input_clear();
	env_free();
	exit(0);
}

static int	check_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[1][i])
	{
		if (ft_isdigit(arg[1][i]) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	bi_exit(char **arg)
{

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (arg[1] == NULL)
		valid_exit_no_arg();
	else if (arg[1] != NULL && arg[2] != NULL)
		too_many_args(arg);
	else if (arg[1] != NULL && arg[2] == NULL)
	{
		if (check_arg(arg) == EXIT_FAILURE)
			non_numeric_args(arg);
		else
		{
			input_clear();
			env_free();
			exit((unsigned char)ft_atoi(arg[1]));
		}
	}
	return (EXIT_SUCCESS);
}
