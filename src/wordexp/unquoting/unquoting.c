/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:16 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 20:46:54 by ajung            ###   ########.fr       */
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

char	**unquoting(char **str)
{
	int		i;
	char	**output;

	i = 0;
	change_quote_status(i);
	(void) output;
	return (str);
	
}
