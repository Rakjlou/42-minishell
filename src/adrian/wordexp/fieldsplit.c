/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:02 by ajung             #+#    #+#             */
/*   Updated: 2022/02/24 18:24:29 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"
#include "env.h"

char	*get_IFS(t_lst *env)
{
	char	*IFS;

	IFS = env_get_value(env, "IFS");
	if (IFS == NULL)
		IFS = " \n\t";
	return (IFS);
}

char	**fieldsplit(char *str)
{
	char	*IFS;
	char	**output;
	t_lst	*env;
	
	env = &_shell()->env;
	IFS = get_IFS(env);
	output = ft_split(str, IFS);
	if (!output)
		return (NULL);
	return (output);
}
