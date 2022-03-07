/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmatrix_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:28:29 by ajung             #+#    #+#             */
/*   Updated: 2022/03/04 20:25:49 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include "unquoting.h"
#include <stdlib.h>


void    cmatrix_iter_init(t_cmatrix_iter *iter, char **data)
{

    iter->data = data;
    iter->i = 0;
    iter->j = -1; //on commence a -1 a cause de iter_incr
}

int	cmatrix_iter_incr(t_cmatrix_iter *iter)
{
	//dprintf(2, "\nstr iter : \ni = %d\nj=%d\n\n", iter->i, iter->j); //a enlever
    char    *current_str;

    current_str = iter->data[iter->i];
    if (current_str == NULL)
        return (EXIT_FAILURE);
	else if (iter->j == -1)
		iter->j = 0;
    else if (current_str[iter->j] == '\0')
    {
        iter->j = 0;
        iter->i++;
    }
    else
	{
		iter->j++;
	}
	return (EXIT_SUCCESS);
}

void	cmatrix_iter_change_line(t_cmatrix_iter *output_iter,
	t_cmatrix_iter *str_iter)
{
	if (output_iter->i != str_iter->i)
	{
		output_iter->i = str_iter->i;
		output_iter->j = 0;
	}
}

void	cmatrix_iter_addc(t_cmatrix_iter *iter, char c)
{
	if (iter->data[iter->i] == NULL)
        return ;
	iter->data[iter->i][iter->j] = c;
}

char    cmatrix_iter_getc(t_cmatrix_iter *iter)
{
    if (iter->data[iter->i] == NULL)
        return (0);
    return (iter->data[iter->i][iter->j]);
}
