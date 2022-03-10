/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:59:07 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 14:55:55 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "shell.h"
#include "libft/libft.h"
#include "libft/ftprintf.h"

/* Prend name key  --> alphanumeique et underscore 
(sauf le premier pas numerique) */

/* 
bash-5.0$ export 1abc
bash: export: `1abc': not a valid identifier
 */

//RETOUR ERREUR 1

static int	valid_name(char **arg)
{
	int	j;

	if (!(ft_isalpha(arg[1][0]) || arg[1][0] == '_'))
		return (EXIT_FAILURE);
	j = 1;
	while (arg[1][j])
	{
		if (arg[1][j] == '_' || ft_isalnum(arg[1][j]))
			j++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	invalid_identifier(char **arg)
{
	ftfprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
		"minishell",
		arg[0],
		arg[1],
		"not a valid identifier");
	return (1);
}

// static void	

int	bi_export(char **arg)
{
	if (arg[1] == NULL)
		env_print_export();
	else if(valid_name(arg) == EXIT_SUCCESS)
		ftfprintf(STDOUT_FILENO, "valid export\n");
	else if (valid_name(arg) == EXIT_FAILURE)
		return(invalid_identifier(arg));
	return (EXIT_SUCCESS);
}
