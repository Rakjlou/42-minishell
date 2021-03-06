/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:59:59 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 17:05:43 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

void	sigint_handler_main_process(int signum)
{
	t_shell	*shell;

	(void) signum;
	shell = _shell();
	shell->last_command_status = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_redisplay();
	return ;
}

int	handle_signal_main_process(void)
{
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR
		|| signal(SIGINT, sigint_handler_main_process) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
