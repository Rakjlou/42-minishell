/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:25:29 by ajung             #+#    #+#             */
/*   Updated: 2022/02/22 19:31:14 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

static int	check_double_quote(char *str)
{
	int	double_quotes;
	int	i;
	
	double_quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			double_quotes++;
		i++;
	}
	if (double_quotes % 2 == 0)
		return (EXIT_SUCCESS);
	else
	{
		dprintf(2, "minishell: syntax error\n");
		return (EXIT_FAILURE);
	}
}

static int	check_single_quote(char *str)
{
	int	single_quotes;
	int	i;
	
	single_quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quotes++;
		i++;
	}
	if (single_quotes % 2 == 0)
		return (EXIT_SUCCESS);
	else	
		return (EXIT_FAILURE);
}

int	syntaxerror(char *str)
{
	if (check_double_quote(str) || check_single_quote(str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
