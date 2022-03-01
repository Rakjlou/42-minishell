/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:33:03 by ajung             #+#    #+#             */
/*   Updated: 2022/03/01 20:10:15 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"



// static char	*return_dollar(void)
// {
// 	char	*output;

// 	output = ft_calloc(sizeof(char), 2);
// 	if (!output)
// 		return (NULL);
// 	output[0] = '$';
// 	return (output);
// }

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

	// if (str[index_dollar + 1] == '\0')
	// 	return (return_dollar());
		dprintf(2, "---GET BEFORE---\n");
	before_dollar = get_before_dollar(str, index_dollar);
		dprintf(2, "before = \'%s\'\n\n", before_dollar);
	if (!before_dollar)
		return (NULL);
	
		dprintf(2, "---GET NEW DOLLAR VALUE---\n");
	new_dollar_value = get_new_dollar_value(str, index_dollar);
		dprintf(2, "new_dollar_value = \'%s\'\n\n", new_dollar_value);
	if (!new_dollar_value)
		return (free(before_dollar), NULL);

		dprintf(2, "---GET AFTER DOLLAR---\n");
	after_dollar = get_after_dollar(str, index_dollar);
		dprintf(2, "after_dollar = \'%s\'\n\n", after_dollar);
	if (!after_dollar)
		return (free(before_dollar), free(new_dollar_value), NULL);

		dprintf(2, "---GET EXPANDED---\n");
	expanded = get_expanded(before_dollar, new_dollar_value, after_dollar);
		dprintf(2, "expanded = \'%s\'\n\n", expanded);
	
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
	dprintf(2, "index_dollar = %d\n\n", index_dollar);
	expanded = expand(str, index_dollar);
	index_dollar = get_index_dollar(expanded);
	if (!expanded)
		return (NULL);
	while (index_dollar >= 0) 
	{
		dprintf(2, "\n-----NOUVEAU TOUR DE BOUCLE------\n\n");
		to_free = expanded;
		expanded = expand(expanded, index_dollar);
		free(to_free);
		if (!expanded)
			return (NULL);
		index_dollar = get_index_dollar(expanded);
	}
	dprintf(2, "--->RESULTAT FINAL = \'%s\'\n\n", expanded);
	return (expanded);
	
}
/*
PROBLEM:
$USER$SHELL --> retour bizarre de env get value
$ tout seul --> disparait

*/
