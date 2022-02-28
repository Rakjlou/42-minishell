/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:06:10 by ajung             #+#    #+#             */
/*   Updated: 2022/02/28 21:10:16 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = index_dollar;
	if (ft_isdigit(str[i + 1]) == 1)
		return (i + 2); //i + 1? i + 2?
	while (str[i])
	{
		if (is_it_name(str[i]) == 0)
			break ;
		i++;
	}
	return (i); //return le char apres la fin du NAME
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
		if (str[i] == '$' && single_quote == CLOSE)
			return (i);
		i++;
	}
	return (-1);
}
