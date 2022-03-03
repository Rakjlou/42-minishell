/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:16 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 18:49:51 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "adrian/test.h"


static int	change_quote_status(int status)
{
	if (status == CLOSE)
		return (OPEN);
	else
		return (CLOSE);
}

// char **quote_get_index(char **str)
// {
	
// }

char	**unquoting(char **str)
{
	int		i;
	char	**output;

	i = 0;
	change_quote_status(i);
	(void) output;
	return (str);
	
}
