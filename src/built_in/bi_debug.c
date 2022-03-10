/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:40:45 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 14:54:43 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

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

void	bi_debug(char *str)
{
	char	**arg;

	if (BUILT_IN_DEBUG == 0)
		return ;
	arg = ft_split(str, " ");
	if (!arg || !arg[0])
		return (free_split(arg));
	if (ft_strncmp(arg[0], "echo", -1) == 0)
		bi_echo(arg);
	free_split(arg);
}
