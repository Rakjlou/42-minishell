/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 18:52:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "ftprintf.h"
#include "input.h"
#include "wordexp.h"
#include "handle_signal.h"
#include "parser/parser.h"

static int	empty(void)
{
	return (0);
}

static void	heredoc_sigint_handler(int signum)
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

int	heredoc_open(t_parser *parser, t_redirection *redirection)
{
	rl_event_hook = empty;
	if (signal(SIGINT, heredoc_sigint_handler) == SIG_ERR)
		return (parser_internal_error(parser), 0);
	redirection->fd = ft_tmpfile(&redirection->filename);
	if (redirection->fd == 0)
		return (parser_internal_error(parser), 0);
	else if (redirection->fd < 0)
		return (redirection_open_file_error(NULL, redirection), 0);
	return (1);
}

void	heredoc_close(t_parser *parser, t_redirection *redirection)
{
	if (close(redirection->fd) == -1)
		return (parser_internal_error(parser));
	redirection->fd = open(redirection->filename, O_RDONLY);
	if (redirection->fd <= 0)
		return (parser_internal_error(parser));
}
