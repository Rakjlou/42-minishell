/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:16:21 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 19:12:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNQUOTING_H
# define UNQUOTING_H

typedef struct s_cmatrix_iterator
{
    char    **data;
    int        current;
    int        i;
    int        j;
    size_t    total;
}    t_cmatrix_iterator;

/*
t_cmatrix_iterator    iter;

cmatrix_iterator_getc(iter); == '"'
cmatrix_iterator_incr(iter);

cmatrix_iterator_init(&iter, fieldsplit(paramexp("$TEST")));
while (iter->current < iter->total)
{
    if (cmatrix_iterator_getc(iter) == '"')
        // DOUBLE QUOTE
    ...
    cmatrix_iterator_incr(iter);
}

void    cmatrix_iterator_init(t_cmatrix_iterator *iter, char **data)
{
    int    i;

    i = 0;
    iter->data = data;
    iter->current = 0;
    iter->i = 0;
    iter->j = 0;
    // while (data[i])
    //     iter->total += ft_strlen(data[i++]);
}

// str++
void    cmatrix_iterator_incr(t_cmatrix_iterator *iter)
{
    char    *current_str;

    current_str = iter->data[iter->i];
    if (iter->data[i] == NULL)
        return ;
    if (current_str[iter->j] == '\0')
    {
        iter->j = 0;
        iter->i++;
    }
    else
        iter->j++;
    iter->current++;

}

// ""

// str[i]
char    cmatrix_iterator_getc(t_cmatrix_iterator *iter)
{
    if (iter->data[i] == NULL)
        return (0);
    return (iter->data[iter->i][iter->j]);
}
*/
#endif
