/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmatrix_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:48:53 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:52:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_cmatrix_join(char **matrix1, char **matrix2)
{
	char	**result;
	size_t	total;
	int		i;
	int		j;

	total = 0;
	if (matrix1)
		total += ft_cmatrix_size(matrix1);
	if (matrix2)
		total += ft_cmatrix_size(matrix2);
	result = ft_calloc(sizeof(char *), total + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (matrix1 && matrix1[i])
		result[j++] = ft_strdup(matrix1[i++]);
	i = 0;
	while (matrix2 && matrix2[i])
		result[j++] = ft_strdup(matrix2[i++]);
	return (result);
}
