/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:16 by ajung             #+#    #+#             */
/*   Updated: 2022/03/07 19:08:37 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include "unquoting.h"
#include <stdlib.h>
#define QUOTE_STATUS_CLOSE 0
#define QUOTE_STATUS_OPEN 1

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**alloc_output(char **str)
{
	int		i;
	char	**output;

	i = 0;
	while (str[i])
		i++;
	output = ft_calloc(sizeof(char *), i + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (str[i])
	{
		output[i] = ft_calloc(sizeof(char), ft_strlen(str[i]) + 1);
		if (!output[i])
			return (free_split(output), NULL);
		i++;
	}
	return (output);
}

static int	on_quote(char c, int *sin_stat, int *dou_stat)
{
	if (c == '\'' && *dou_stat == QUOTE_STATUS_CLOSE)
		return (EXIT_SUCCESS);
	else if (c == '\"' && *sin_stat == QUOTE_STATUS_CLOSE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static void	unquote(t_cmatrix_iter *output_iter, t_cmatrix_iter *str_iter)
{
	int		sin_stat;
	int		dou_stat;
	char	c;

	output_iter->j = 0;
	sin_stat = QUOTE_STATUS_CLOSE;
	dou_stat = QUOTE_STATUS_CLOSE;
	while (cmatrix_iter_incr(str_iter) == EXIT_SUCCESS)
	{
		c = cmatrix_iter_getc(str_iter);
		while (on_quote(c, &sin_stat, &dou_stat) == EXIT_SUCCESS)
		{
			skip_quote(str_iter, &sin_stat, &dou_stat);
			c = cmatrix_iter_getc(str_iter);
		}
		cmatrix_iter_change_line(output_iter, str_iter);
		cmatrix_iter_addc(output_iter, c);
		output_iter->j++;
	}
}

char	**unquoting(char **str)
{
	char				**output;
	t_cmatrix_iter		str_iter;
	t_cmatrix_iter		output_iter;

	cmatrix_iter_init(&str_iter, str);
	output = alloc_output(str);
	if (!output)
		return (NULL);
	cmatrix_iter_init(&output_iter, output);
	unquote(&output_iter, &str_iter);
	return (output_iter.data);
}
