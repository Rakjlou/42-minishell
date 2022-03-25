/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:05:55 by ajung             #+#    #+#             */
/*   Updated: 2022/03/25 19:01:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_signal.h"

void	sigint_handler_heredoc(int signum)
{
	t_shell	*shell;

	(void)signum;
	shell = _shell();
	shell->last_command_status = 130;
	shell->parser.status = PARSER_HEREDOC_INTERRUPTED;
	handle_signals(MAIN_PROCESS);
	ft_putstr_fd("\n", STDIN_FILENO);
	rl_on_new_line();
	rl_done = 1;
}

int	handle_signal_heredoc(void)
{
	if (signal(SIGINT, sigint_handler_heredoc) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
