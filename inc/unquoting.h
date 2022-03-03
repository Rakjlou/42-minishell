/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:16:21 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 19:49:28 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNQUOTING_H
# define UNQUOTING_H

typedef struct s_cmatrix_iterator
{
    char    **data;
    int        i;
    int        j;
}    t_cmatrix_iterator;


t_cmatrix_iterator    iter;

cmatrix_iterator_getc(iter); == '"'
cmatrix_iterator_incr(iter);

cmatrix_iterator_init(&iter, fieldsplit(paramexp("$TEST")));


while (iter->data[iter->i] != NULL)
{
    if (cmatrix_iterator_getc(iter) == '"')
        // DOUBLE QUOTE
		// J++ (CHAR DELETE)
    ...
    cmatrix_iterator_incr(iter);
}

void    cmatrix_iterator_init(t_cmatrix_iterator *iter, char **data)
{

    iter->data = data;
    iter->i = 0;
    iter->j = 0;
}

// str++
void    cmatrix_iterator_incr(t_cmatrix_iterator *iter)
{
    char    *current_str;

    current_str = iter->data[iter->i];
    if (current_str == NULL)
        return ;
    if (current_str[iter->j] == '\0')
    {
        iter->j = 0;
        iter->i++;
    }
    else
        iter->j++;
}

// ""

// str[i]
char    cmatrix_iterator_getc(t_cmatrix_iterator *iter)
{
    if (iter->data[iter->i] == NULL)
        return (0);
    return (iter->data[iter->i][iter->j]);
}

#endif
