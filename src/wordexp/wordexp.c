/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/10 21:45:01 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"

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

// TODO: "'                  '" actuellement est split, ne devrait pas
char	**wordexp(char *str)
{
	char	*param_exp_output;
	char	**field_split_output;
	char	**pathname_output;
	char	**output;

	param_exp_output = paramexp(str);
	field_split_output = fieldsplit(param_exp_output);
	(void) pathname_output;
	output = unquoting(field_split_output);
	if (WORDEXP_DEBUG == 1)
		debug(output); //A DELETE
	free(param_exp_output);
	free_split(field_split_output);
	return (output);
}
