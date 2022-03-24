/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:05:55 by ajung             #+#    #+#             */
/*   Updated: 2022/03/24 19:18:29 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

void	sigint_handler_heredoc(int mescouilles)
{
	t_shell	*shell;
	
	shell = _shell();
	(void) mescouilles;
	shell->last_command_status = 130;
	ftprintf("\n");
	return ;
}

int	handle_signal_heredoc(void)
{
	//readline function ?
	if (signal(SIGINT, sigint_handler_heredoc) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
