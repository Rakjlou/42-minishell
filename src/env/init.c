/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:26:56 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 20:46:39 by nsierra-         ###   ########.fr       */
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
	char	*value;
	char	*key;
	int		ret;

	ret = EXIT_SUCCESS;
	value = get_value(str);
	if (value == NULL)
		return (EXIT_FAILURE);
	key = get_key(str);
	if (key == NULL)
		return (free(value), EXIT_FAILURE);
	else if (!key || env_set_value(key, value) == EXIT_FAILURE)
		ret = EXIT_FAILURE;
	free(key);
	free(value);
	return (ret);
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
