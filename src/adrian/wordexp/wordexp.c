/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:22:02 by ajung             #+#    #+#             */
/*   Updated: 2022/02/28 21:46:41 by ajung            ###   ########.fr       */
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
	param_exp_output = paramexp(str);
	
	//PART 2 field splitting
	field_split_output = fieldsplit(param_exp_output);

	//PART 3 Pathname expansion
	//version simplifie pour maintenant

	//PART 4 Unquoting
	
    return (field_split_output);
}
