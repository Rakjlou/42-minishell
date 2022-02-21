/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:22:02 by ajung             #+#    #+#             */
/*   Updated: 2022/02/21 17:22:39 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

char  **ft_wordexp(t_lst *words);
t_lst  *ft_wordexp(t_lst *words);

char  **ft_wordexp(t_lst *lst)
{
    t_iter  iter;
    t_token *token;
    char    *content;
    char    **result;

    iter_init(&iter, lst, ASC);
    while (iter_next(&iter))
    {
        token = (t_token *)iter.data;
        content = token->raw;
    }
    return (result);
}
