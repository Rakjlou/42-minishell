/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 18:01:11 by nsierra-         ###   ########.fr       */
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

static void	heredoc_eof_warning(t_parser *parser, char *stop)
{
	parser->status = PARSER_STATUS_FINISHED;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: here-document delimited by end-of-file (wanted `%s')\n",
		"minishell",
		"warning",
		stop);
}

static int	heredoc_write(
	t_parser *parser,
	t_redirection *redirection,
	char *line,
	int quoted)
{
	char	*written;

	written = line;
	if (!quoted)
	{
		written = paramexp(line);
		if (written == NULL)
			return (parser_internal_error(parser), 0);
	}
	if (write(redirection->fd, written, ft_strlen(written)) == -1
		|| write(redirection->fd, "\n", 1) == -1)
	{
		if (!quoted)
			free(written);
		return (parser_internal_error(parser), 0);
	}
	if (!quoted)
		free(written);
	return (1);
}

int	heredoc_request(t_parser *parser, t_redirection *redir)
{
	int		quoted;

	if (!heredoc_open(parser, redir))
		return (0);
	redir->heredoc_stop = heredoc_wordexp(redir);
	if (redir->heredoc_stop == NULL)
		return (parser_internal_error(parser), 0);
	quoted = ft_strlen(redir->heredoc_stop) != ft_strlen(redir->arg->raw);
	while (parser->status == PARSER_STATUS_DEFAULT)
	{
		redir->heredoc_line = input_get_line2();
		if (redir->heredoc_line == NULL)
			return (heredoc_eof_warning(parser, redir->heredoc_stop),
				heredoc_close(parser, redir), handle_signals(MAIN_PROCESS), 1);
		else if (!ft_strncmp(redir->heredoc_stop, redir->heredoc_line, -1))
			return (heredoc_close(parser, redir),
				handle_signals(MAIN_PROCESS), 1);
		else if (!heredoc_write(parser, redir, redir->heredoc_line, quoted))
			return (handle_signals(MAIN_PROCESS), 0);
		free(redir->heredoc_line);
		redir->heredoc_line = NULL;
	}
	handle_signals(MAIN_PROCESS);
	return (parser->status == PARSER_STATUS_DEFAULT);
}
