/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:33:03 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 20:36:09 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_wordexp.h"

static char	*get_expanded(char *before_dollar, char *new_dollar_value,
	char *after_dollar)
{
	char	*expanded;
	char	*before_and_value;

	before_and_value = ft_strjoin(before_dollar, new_dollar_value);
	if (!before_and_value)
		return (NULL);
	expanded = ft_strjoin(before_and_value, after_dollar);
	free(before_and_value);
	return (expanded);
}

static char	*expand(char *str, int index_dollar)
{
	char	*expanded;
	char	*before_dollar;
	char	*new_dollar_value;
	char	*after_dollar;

	before_dollar = get_before_dollar(str, index_dollar);
	if (!before_dollar)
		return (NULL);
	new_dollar_value = get_new_dollar_value(str, index_dollar);
	if (!new_dollar_value)
		return (free(before_dollar), NULL);
	after_dollar = get_after_dollar(str, index_dollar);
	if (!after_dollar)
		return (free(before_dollar), free(new_dollar_value), NULL);
	expanded = get_expanded(before_dollar, new_dollar_value, after_dollar);
	free(before_dollar);
	free(new_dollar_value);
	free(after_dollar);
	return (expanded);
}

char	*paramexp(char *str)
{
	char	*expanded;
	char	*to_free;
	int		index_dollar;

	index_dollar = get_index_dollar(str);
	expanded = expand(str, index_dollar);
	index_dollar = get_index_dollar(expanded);
	if (!expanded)
		return (NULL);
	while (index_dollar >= 0)
	{
		to_free = expanded;
		expanded = expand(expanded, index_dollar);
		free(to_free);
		if (!expanded)
			return (NULL);
		index_dollar = get_index_dollar(expanded);
	}
	wordexp_debug("Paramexp '%s' --> '%s'\n", str, expanded);
	return (expanded);
}
