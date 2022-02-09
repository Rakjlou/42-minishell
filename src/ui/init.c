/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:17:57 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 00:33:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_input.h"
#include "libft.h"

void	ui_init(t_user_input *ui, char *raw)
{
	ft_bzero(ui, sizeof(t_user_input));
	ui->raw = raw;
	ui->size = (unsigned long)ft_strlen(raw);
	ui->cursor = 0;
}
