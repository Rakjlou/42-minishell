/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 22:25:29 by nsierra-         ###   ########.fr       */
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
	field_split_output = fieldsplit(param_exp_output);
	glob_output = glob(field_split_output);
	unquoting_output = unquoting(glob_output);
	if (WORDEXP_DEBUG == 1)
		debug(unquoting_output);
	free(param_exp_output);
	free_split(field_split_output);
	free_split(glob_output);
	return (unquoting_output);
}
