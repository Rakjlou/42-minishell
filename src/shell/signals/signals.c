/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 19:04:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

static int	empty(void)
{
	return (0);
}

int	handle_signals(int status)
{
	if (status == MAIN_PROCESS)
	{
		if (handle_signal_main_process() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (status == HEREDOC)
	{
		rl_event_hook = empty;
		if (handle_signal_heredoc() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (status == CHILD)
	{
		if (handle_signal_child() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (status == PARENT)
	{
		if (handle_signal_parent() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
