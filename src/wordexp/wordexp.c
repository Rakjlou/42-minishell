/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 20:04:59 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include <stdlib.h>
#define WORDEXP_DEBUG 0

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/* static int	search_quote(char *str)
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
} */
	// if (search_quote == EXIT_SUCCESS)
	// 	pathname_exp_output = field_split_output;
	// else if (search_quote(EXIT_FAILURE))
	// 	pathname_exp_output = pathname_exp(field_split_output);
	//char	**pathname_exp_output;

char	**wordexp(char *str)
{
	char	*param_exp_output;
	char	**field_split_output;
	char	**unquoting_output;

	param_exp_output = paramexp(str);
	field_split_output = fieldsplit(param_exp_output);
	unquoting_output = unquoting(field_split_output);
	if (WORDEXP_DEBUG == 1)
		debug(unquoting_output);
	free(param_exp_output);
	free_split(field_split_output);
	return (unquoting_output);
}
