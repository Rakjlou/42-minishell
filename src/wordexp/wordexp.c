/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/04 20:59:15 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	print_split(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		dprintf(2, "- %s\n", str[i]);
		i++;
	}
}

static void debug(char **fs_output, char **unquote_output)
{
	dprintf(2, "\n------FS_OUTPUT-----\n");
	print_split(fs_output);
	dprintf(2, "\n---UNQUOTE_OUTPUT---\n");
	print_split(unquote_output);
}

char	**wordexp(char *str)
{
	char	*param_exp_output;
	char	**field_split_output;
	char	**pathname_output;
	char	**output;

	(void) param_exp_output;
	(void) pathname_output;
	(void) output;

	//PART 1 Param expansion
	param_exp_output = paramexp(str);

	//PART 2 field splitting
	field_split_output = fieldsplit(param_exp_output);
	

	//PART 3 Pathname expansion
	//version simplifie pour maintenant

	//PART 4 Unquoting
	output = unquoting(field_split_output);
	debug(field_split_output, output);
	free(param_exp_output);
	free_split(field_split_output);
	return (output);
}
