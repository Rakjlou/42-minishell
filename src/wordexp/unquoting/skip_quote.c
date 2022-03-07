/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:04:50 by ajung             #+#    #+#             */
/*   Updated: 2022/03/04 19:39:15 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unquoting.h"
# include "wordexp.h"

# define QUOTE_STATUS_CLOSE 0
# define QUOTE_STATUS_OPEN 1

static void	change_quote_status(int *status)
{
	if (*status == QUOTE_STATUS_CLOSE)
		*status = QUOTE_STATUS_OPEN;
	else
		*status = QUOTE_STATUS_OPEN;
}

static void	incr_and_change_status(t_cmatrix_iter *iter, int *status)
{
		cmatrix_iter_incr(iter);
		change_quote_status(status);
}

void	skip_quote(t_cmatrix_iter *iter, int *sin_stat, int *dou_stat)
{
	if (cmatrix_iter_getc(iter) == '\'' && *dou_stat == QUOTE_STATUS_CLOSE)
		incr_and_change_status(iter, sin_stat);
	else if (cmatrix_iter_getc(iter) == '\"' && sin_stat == QUOTE_STATUS_CLOSE)
		incr_and_change_status(iter, dou_stat);
}
