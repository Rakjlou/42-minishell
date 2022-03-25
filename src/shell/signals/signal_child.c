/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:10:27 by ajung             #+#    #+#             */
/*   Updated: 2022/03/25 19:57:12 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

// void	sigint_handler_child(int signum)
// {
// 	(void) signum;
// 	ft_putstr_fd("\n", STDIN_FILENO);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

int	handle_signal_child(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR
		|| signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
