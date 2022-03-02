/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:22:02 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:16:12 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

char  **ft_wordexp(char *str)
{
    
	char	*param_exp_output;
	char	**field_split_output;
	char	**pathname_output;
	char	**output;
	
	(void) param_exp_output;
	(void) pathname_output;
	(void) output;
	
	//PART 0 Check syntax error
	if (syntaxerror(str) == EXIT_FAILURE)
		return (NULL);
	

	//PART 1 Param expansion
	dprintf(2, "\n\nStarting paramexp\n");
	param_exp_output = paramexp(str);

	//PART 2 field splitting
	field_split_output = fieldsplit(param_exp_output);

	//PART 3 Pathname expansion
	//version simplifie pour maintenant

	//PART 4 Unquoting
	free(param_exp_output);
	dprintf(2, "\n\n\n\n\n");
    return (field_split_output);
}
