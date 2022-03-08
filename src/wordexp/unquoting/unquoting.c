/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:16 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 19:14:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"

static int	change_quote_status(int status)
{
	if (status == QUOTE_STATUS_CLOSE)
		return (QUOTE_STATUS_OPEN);
	else
		return (QUOTE_STATUS_CLOSE);
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
