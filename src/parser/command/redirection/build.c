/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 06:04:45 by nsierra-         ###   ########.fr       */
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

static int	handle_heredoc(t_parser *parser, t_redirection *redirection)
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
			return (heredoc_eof_warning(parser, stop),
				free(line), free(new_arg), 0);
		else if (!ft_strncmp(stop, line, -1))
		{
			redirection->arg->raw = new_arg;
			return (free(line), free(new_arg), 1);
		}
		else if (!heredoc_join(parser, &new_arg, line))
			return (free(line), 0);
		free(line);
	}
}

void	command_redirection_build(t_parser *parser, t_iter *iter, t_lst *lst)
{
	t_token			*type;
	t_token			*arg;
	t_redirection	*redirection;

	type = iter->data;
	if (!parser_next_token_noendl(parser, iter))
		return ;
	else if (!token_is(iter->data, TOK_TOKEN))
		return (parser_unexpected_token(parser, iter->data));
	arg = iter->data;
	arg->type = TOK_WORD;
	redirection = ft_calloc(sizeof(t_redirection), 1);
	if (redirection == NULL)
		return (parser_internal_error(parser));
	redirection->type = type;
	redirection->arg = arg;
	if (!lst_push_back(lst, redirection))
		parser_internal_error(parser);
	else if (token_is(redirection->type, TOK_DLESS))
		handle_heredoc(parser, redirection);
	parser_next_token(parser, iter);
}
