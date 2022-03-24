/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 18:32:30 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

int	handle_signals(int status)
{
	if (status == MAIN_PROCESS)
	{
		if (handle_signal_main_process() == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (status == HEREDOC)
	{
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
