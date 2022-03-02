/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:02 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:06:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"
#include "env.h"

char	*get_ifs(t_lst *env)
{
	char	*ifs;

	ifs = env_get_value(env, "ifs");
	if (ifs == NULL)
		ifs = " \n\t";
	return (ifs);
}

char	**fieldsplit(char *str)
{
	char	*ifs;
	char	**output;
	t_lst	*env;

	env = &_shell()->env;
	ifs = get_ifs(env);
	output = ft_split(str, ifs);
	if (!output)
		return (NULL);
	return (output);
}
