/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 22:18:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"

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
	free(param_exp_output);
	//free(field_split_output);
	return (field_split_output);
}
