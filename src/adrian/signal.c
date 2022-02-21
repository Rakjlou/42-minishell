/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:27:55 by ajung             #+#    #+#             */
/*   Updated: 2022/02/21 21:23:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		//rl_on_new_line();
		//rl_replace_line("", 0);
		//rl_redisplay();
	}
}

int	handle_signal()
{
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		exit (EXIT_FAILURE);
	if (signal(SIGINT, handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
