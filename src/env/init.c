/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:26:56 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 21:49:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ftprintf.h"

static char	*get_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	return (ft_substr(str, 0, i));
}

static char	*get_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=' && str[i + 1] == 0)
		return (NULL);
	return (ft_substr(str, i + 1, -1));
}

static int	env_load_envp_variable(char *str)
{
	char			*value;
	char			*key;

	value = get_value(str);
	key = get_key(str);
	if (!key || env_set_value(key, value) == EXIT_FAILURE)
		return (free(key), free(value), EXIT_FAILURE);
	return (free(key), free(value), EXIT_SUCCESS);
}

int	env_init(void)
{
	char	**envp;
	int		i;

	envp = _shell()->param.env;
	i = 0;
	while (envp && envp[i])
	{
		if (env_load_envp_variable(envp[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
