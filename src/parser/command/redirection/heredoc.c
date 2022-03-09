/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 21:08:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "input.h"
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

static int	heredoc_join(t_parser *parser, char **dest, char *str)
{
	char	*joined;
	char	*tmp;

	joined = ft_strjoin(*dest, str);
	if (!joined)
		return (parser_internal_error(parser), 0);
	tmp = joined;
	joined = ft_strjoin(joined, "\n");
	if (!joined)
		return (parser_internal_error(parser), free(tmp), 0);
	free(tmp);
	free(*dest);
	*dest = joined;
	return (1);
}

/* Deserves a small refacto to write natively into a tmpfile */
static void	heredoc_set_arg(t_redirection *redirection, char *new_arg)
{
	free(redirection->arg->raw);
	redirection->arg->raw = new_arg;
}

int	heredoc_request(t_parser *parser, t_redirection *redirection)
{
	char	*stop;
	char	*new_arg;
	char	*line;

	stop = redirection->arg->raw;
	new_arg = ft_calloc(sizeof(char), 1);
	if (!new_arg)
		return (parser_internal_error(parser), 0);
	while (42)
	{
		line = input_get_line2();
		if (line == NULL)
		{
			return (heredoc_eof_warning(parser, stop),
				heredoc_set_arg(redirection, new_arg),
				free(line), 1);
		}
		else if (!ft_strncmp(stop, line, -1))
			return (heredoc_set_arg(redirection, new_arg), free(line), 1);
		else if (!heredoc_join(parser, &new_arg, line))
			return (free(line), 0);
		free(line);
	}
}
