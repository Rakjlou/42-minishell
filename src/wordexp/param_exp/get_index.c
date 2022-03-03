/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:06:10 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:11:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wordexp.h"
#include "adrian/test.h"

static int	is_it_name(char c)
{
	if (c == '_')
		return (1);
	if (ft_isalnum(c) == 1)
		return (1);
	return (0);
}

static int	change_quote_status(int status)
{
	if (status == CLOSE)
		return (OPEN);
	else
		return (CLOSE);
}

int	get_index_end(char *str, int index_dollar)
{
	int	i;

	i = index_dollar + 1;
	if (ft_isdigit(str[i]) == 1)
		return (i + 1);
	while (str[i])
	{
		if (is_it_name(str[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	get_index_dollar(char *str)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = CLOSE;
	double_quote = CLOSE;
	while (str[i])
	{
		if (str[i] == '\'' && double_quote == CLOSE)
			single_quote = change_quote_status(single_quote);
		if (str[i] == '\"' && single_quote == CLOSE)
			double_quote = change_quote_status(double_quote);
		if (str[i] == '$' && single_quote == CLOSE
			&& str[i + 1] && str[i + 1] != ' ')
			return (i);
		i++;
	}
	return (-1);
}
