/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:22:02 by ajung             #+#    #+#             */
/*   Updated: 2022/02/22 19:30:09 by ajung            ###   ########.fr       */
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
	//need env
	
	//PART 2 field splitting
	field_split_output = fieldsplit(str);

	//PART 3 Pathname expansion

	//PART 4 Unquoting
	
    return (field_split_output);
}
