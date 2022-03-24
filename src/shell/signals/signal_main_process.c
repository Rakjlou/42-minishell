/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:59:59 by ajung             #+#    #+#             */
/*   Updated: 2022/03/24 19:41:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

void	sigint_handler_main_process(int mescouilles)
{
	t_shell	*shell;

	shell = _shell();
	(void) mescouilles;
	shell->last_command_status = 130;
	ft_putstr_fd("\n", STDIN_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
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
