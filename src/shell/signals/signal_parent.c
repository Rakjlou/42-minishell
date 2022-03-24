/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:04:49 by ajung             #+#    #+#             */
/*   Updated: 2022/03/24 18:33:01 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

int	handle_signal_parent(void)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
