/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 21:28:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <dirent.h>
#include "ftlst.h"
#include "ftprintf.h"

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

char	**wordexp(char *str)
{
	char	*param_exp_output;
	char	**field_split_output;
	char	**unquoting_output;
	char	**glob_output;

	param_exp_output = paramexp(str);
	if (param_exp_output == NULL)
		return (NULL);
	field_split_output = fieldsplit(param_exp_output);
	if (field_split_output == NULL)
		return (free(param_exp_output), NULL);
	glob_output = glob(field_split_output);
	if (glob_output == NULL)
		return (free(param_exp_output),
			free_split(field_split_output), NULL);
	unquoting_output = unquoting(glob_output);
	if (unquoting_output == NULL)
		return (free(param_exp_output), free_split(field_split_output),
			free_split(glob_output), NULL);
	debug(unquoting_output);
	free(param_exp_output);
	free_split(field_split_output);
	free_split(glob_output);
	return (unquoting_output);
}
