/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:25:27 by ajung             #+#    #+#             */
/*   Updated: 2022/02/17 20:28:47 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

t_shell	*_shell(void)
{
	static t_shell	shell;
	static int		check = 0;

	if (check == 0)
	{
		check = 1;
		ft_bzero(&shell, sizeof(t_shell));
	}
	return (&shell);
}
