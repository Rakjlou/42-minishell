/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:10:27 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 16:55:50 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

void	sigint_handler_child(int signum)
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

int	handle_signal_child(void)
{
	if (signal(SIGINT, sigint_handler_child) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
