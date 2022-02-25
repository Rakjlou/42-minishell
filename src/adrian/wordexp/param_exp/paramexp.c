/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:04 by ajung             #+#    #+#             */
/*   Updated: 2022/02/25 19:43:56 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"


int	quote_status(int status)
{
	if (status == 0)
		return (1);
	else
		return (0);
}

int	where_is_$(char *str)
{
	int	i;
	int	single_quote;

	i = 0;
	single_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quote = quote_status(single_quote);
		if (str[i] == '$' && single_quote == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	get_start_var(char *str)
{
	int	start;

	start = where_is_$(str);

	if (str[start] == NULL)
		return (-1);
	return (start);
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	get_end_var(char *str, int start)
{
	int		i;
	char	*charset;

	
	charset =" \n\t\"\'";
	i = 0;
	while (str[i] && is_in_charset(str[i], charset))
		i++;
	return (i);
}

char	*expand(char *str)
{
	int		i;
	int		start;
	int 	end;
	char	*output;

	i = 0;
	end = -1;
	output == NULL;
	start = get_start_var(str);
	if (start >= 0)
		end = get_end_var(str, start);
	if (end >= 0)
		output = ft_substr(str, start, end - start + 1);
	return (free(str), output);	
}

char	*paramexp(char *str)
{
	int		i;
	char	*str_expand;
	
	i = 0;
	//do while
	str_expand = expand(str);
	if (!str_expand)
		return (NULL);
	while (str_expand != NULL) //va toujours returner NULL, doit s'arretter un 
								//coup avant ou detecter avec fonction (appeler whereis $)
	{
		str_expand = expand(str_expand);
	}
	return (str_expand);
}
