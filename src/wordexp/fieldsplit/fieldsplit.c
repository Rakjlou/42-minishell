/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:02 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 18:50:58 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_ifs(void)
{
	char	*ifs;

	ifs = env_get_value("IFS");
	if (ifs == NULL)
		ifs = " \n\t";
	return (ifs);
}

static int	search_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

char	**fieldsplit(char *str)
{
	char	*ifs;
	char	**output;

	ifs = get_ifs();
	if (search_quote(str) == EXIT_SUCCESS)
		output = ft_split(str, "");
	else
		output = ft_split(str, ifs);
	if (!output)
		return (NULL);
	return (output);
}
