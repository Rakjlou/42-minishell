/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:26:56 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:36:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"
#include "env.h"

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
	return (ft_substr(str, i + 1, -1));
}

static int	fill_content(char *str, t_lst *env)
{
	t_env_content	*content;
	char			*value;
	char			*key;

	value = get_value(str);
	key = get_key(str);
	if (!key || !value)
		return (EXIT_FAILURE);
	content = env_content_new(key, value);
	if (!content)
		return (free(key), free(value), EXIT_FAILURE);
	lst_push_back(env, content);
	return (free(key), free(value), EXIT_SUCCESS);
}

int	env_init(void)
{
	t_shell	*shell;
	char	**envp;
	int		i;

	shell = _shell();
	envp = shell->args.env;
	i = 0;
	while (envp[i])
	{
		if (fill_content(envp[i], &shell->env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	env_print(&shell->env);
	return (EXIT_SUCCESS);
}
