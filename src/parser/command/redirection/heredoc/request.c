/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 17:03:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "ftprintf.h"
#include "input.h"
#include "wordexp.h"
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

static int	heredoc_open(t_parser *parser, t_redirection *redirection)
{
	redirection->fd = ft_tmpfile(&redirection->filename);
	if (redirection->fd == 0)
		return (parser_internal_error(parser), 0);
	else if (redirection->fd < 0)
		return (redirection_open_file_error(NULL, redirection), 0);
	return (1);
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

static void	heredoc_close(t_parser *parser, t_redirection *redirection)
{
	if (close(redirection->fd) == -1)
		return (parser_internal_error(parser));
	redirection->fd = open(redirection->filename, O_RDONLY);
	if (redirection->fd <= 0)
		return (parser_internal_error(parser));
}

int	heredoc_request(t_parser *parser, t_redirection *redir)
{
	char	*stop;
	char	*line;
	int		quoted;

	if (!heredoc_open(parser, redir))
		return (0);
	stop = heredoc_get_stop_token(redir);
	if (stop == NULL)
		return (parser_internal_error(parser), 0);
	quoted = ft_strlen(stop) != ft_strlen(redir->arg->raw);
	while (parser->status == PARSER_STATUS_DEFAULT)
	{
		line = input_get_line2();
		if (line == NULL)
		{
			return (heredoc_eof_warning(parser, stop),
				heredoc_close(parser, redir), free(stop), 1);
		}
		else if (!ft_strncmp(stop, line, -1))
			return (heredoc_close(parser, redir), free(line), free(stop), 1);
		else if (!heredoc_write(parser, redir, line, quoted))
			return (free(line), free(stop), 0);
		free(line);
	}
	return (free(stop), 1);
}
