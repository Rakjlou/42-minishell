/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:04:25 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:05:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"
#include "env.h"


char	*get_before_dollar(char *str, int index_dollar)
{
	char	*output;

	output = ft_substr(str, 0, index_dollar); //1 pas assez?
	if (!output)
		return (NULL);
	return (output);
}

static char	*get_raw_dollar_var(char *str, int index_dollar)
{
	char	*output;
	int		index_end;

	index_end = get_index_end(str, index_dollar);
	if (index_end > 0)
		index_end--;
	output = ft_substr(str, index_dollar + 1, index_end - index_dollar);
	if (!output)
		return (NULL);
	return (output);
}

char	*get_new_dollar_value(char *str, int index_dollar)
{
	char	*raw;
	t_shell	*shell;
	char	*value;

	if (index_dollar < 0)
		return (ft_calloc(sizeof(char), 1));
	raw = get_raw_dollar_var(str, index_dollar);
	dprintf(2, "raw = \'%s\'\n", raw);
	if (!raw)
		return (NULL);
	if (ft_isdigit(raw[0] == 1))
	{
		dprintf(2, "detecte raw[0] est numerique \n");
		return (free(raw), ft_calloc(sizeof(char), 1));
	}	
	shell = _shell();
	value = env_get_value(&(shell->env), raw);
	if (!value) //Si on a pas trouve de value corresspondant a la key
		value = ft_calloc(sizeof(char), 1);
	return (free(raw), ft_strdup(value));
}

char	*get_after_dollar(char *str, int index_dollar)
{
	char	*output;
	int		index_end;

	if (index_dollar < 0)
		return (ft_calloc(sizeof(char), 1));
	index_end = get_index_end(str, index_dollar);
	output = ft_substr(str, index_end, -1);
	if (!output)
		return (NULL);
	return (output);
}
