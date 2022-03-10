/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:59:07 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 21:18:37 by ajung            ###   ########.fr       */
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

// static int	valid_name(char **arg)
// {
// 	int	j;

// 	if (!(ft_isalpha(arg[1][0]) || arg[1][0] == '_'))
// 		return (EXIT_FAILURE);
// 	j = 1;
// 	while (arg[1][j])
// 	{
// 		if (arg[1][j] == '_' || ft_isalnum(arg[1][j]))
// 			j++;
// 		else
// 			return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

static int	valid_name(char *arg)
{
	int	j;

	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (EXIT_FAILURE);
	j = 1;
	while (arg[j])
	{
		if (arg[j] == '_' || ft_isalnum(arg[j]))
			j++;
		else
			return (free(arg), EXIT_FAILURE);
	}
	return (free(arg), EXIT_SUCCESS);
}

// static int	invalid_identifier(char **arg)
// {
// 	ftfprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
// 		"minishell",
// 		arg[0],
// 		arg[1],
// 		"not a valid identifier");
// 	return (1);
// }

static void	invalid_identifier(char *arg, int *output)
{
	ftfprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
		"minishell",
		"export",
		arg,
		"not a valid identifier");
	*output = 1;
}

static void	export_to_env(char *arg)
{
	char	*key;
	char	*value;

	key = keyval_get_key(arg);
	value = keyval_get_value(arg);
	env_set_value(key, value);
	free(key);
	free(value);
}

static void check_args(char **args, int *output)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (valid_name(keyval_get_key(args[i])) == EXIT_FAILURE)
			invalid_identifier(args[i], output);
		else
			export_to_env(args[i]);
		i++;
	}
}	

int	bi_export(char **args)
{
	int	output;
	
	output = EXIT_SUCCESS;
	if (args[1] == NULL)
		env_print_export();
	else
		check_args(args, &output);
	return (output);
}
