/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 19:04:44 by nsierra-         ###   ########.fr       */
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

int	heredoc_open(t_parser *parser, t_redirection *redirection)
{
	if (handle_signals(HEREDOC) == EXIT_FAILURE)
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
