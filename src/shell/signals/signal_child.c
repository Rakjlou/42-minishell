/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:10:27 by ajung             #+#    #+#             */
/*   Updated: 2022/03/24 18:33:30 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

int	handle_signal_child(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
