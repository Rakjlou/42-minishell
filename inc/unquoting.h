/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquoting.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:16:21 by ajung             #+#    #+#             */
/*   Updated: 2022/03/07 19:11:45 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNQUOTING_H
# define UNQUOTING_H

typedef struct s_cmatrix_iter
{
	char	**data;
	int		i;
	int		j;
}	t_cmatrix_iter;

void	cmatrix_iter_init(t_cmatrix_iter *iter, char **data);
int		cmatrix_iter_incr(t_cmatrix_iter *iter);
char	cmatrix_iter_getc(t_cmatrix_iter *iter);
void	cmatrix_iter_change_line(t_cmatrix_iter *output_iter,
			t_cmatrix_iter *str_iter);
void	cmatrix_iter_addc(t_cmatrix_iter *iter, char c);
void	skip_quote(t_cmatrix_iter *iter, int *sin_stat, int *dou_stat);

#endif
