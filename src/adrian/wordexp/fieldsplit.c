/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:02 by ajung             #+#    #+#             */
/*   Updated: 2022/02/23 17:11:03 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

static int	check_IFS()
{
	return (EXIT_SUCCESS);
/* 	if (IFS est set)
		return (EXIT_SUCCESS);
	else if (IFS est unset)
		return (EXIT_FAILURE) */
}

char	*get_IFS()
{
	char	*IFS;

	IFS = " \n\t";

	return (IFS);
}

void	aff_output(char **output)
{
	int	i;

	i= 0;
	while (output[i])
	{
		dprintf(2, "%s\n", output[i]);
		i++;
	}
}

char	**fieldsplit(char *str)
{
	char	*IFS;
	char	**output;
	
	if (check_IFS() == EXIT_FAILURE)
		IFS = " \n\t";
	else
		IFS = get_IFS();
	//je suppose que ft_split ne split pas si charset est NULL
	output = ft_split(str, IFS);
	if (!output)
		return (NULL);
	//aff_output(output);
	return (output);
}
