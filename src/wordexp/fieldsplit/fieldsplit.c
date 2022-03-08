/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:02 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 19:15:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_ifs(void)
{
	char	*ifs;

	ifs = env_get_value("IFS");
	if (ifs == NULL)
		ifs = " \n\t";
	return (ifs);
}

char	**fieldsplit(char *str)
{
	char	*ifs;
	char	**output;

	ifs = get_ifs();
	output = ft_split(str, ifs);
	if (!output)
		return (NULL);
	return (output);
}
