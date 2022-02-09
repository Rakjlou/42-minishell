/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:15:00 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 00:33:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_input.h"
#include "libft.h"

void	ui_skip_whitespace(t_user_input *ui)
{
	while (ft_isspace(ui_peek(ui)))
		ui_next(ui);
}
