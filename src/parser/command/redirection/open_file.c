/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/08 23:12:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftprintf.h"
#include "parser/parser.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static void	init_flags_and_modes(int flags[TOK_TOTAL], int modes[TOK_TOTAL])
{
	ft_bzero(flags, TOK_TOTAL * sizeof(int));
	flags[TOK_SGREAT] = O_WRONLY | O_CREAT | O_TRUNC;
	flags[TOK_DGREAT] = O_WRONLY | O_CREAT | O_APPEND;
	flags[TOK_SLESS] = O_RDONLY;
	ft_bzero(modes, TOK_TOTAL * sizeof(int));
	modes[TOK_SGREAT] = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	modes[TOK_DGREAT] = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
}

void	redirection_open_file_error(
	t_command *command,
	t_redirection *redirection)
{
	if (command != NULL)
		command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		redirection->filename,
		strerror(errno));
}

int	redirection_open_file(t_command *command, t_redirection *redirection)
{
	int		flags[TOK_TOTAL];
	int		modes[TOK_TOTAL];
	int		candidate;
	t_token	*r;

	r = redirection->type;
	init_flags_and_modes(flags, modes);
	candidate = open(redirection->filename, flags[r->type], modes[r->type]);
	if (candidate <= 0)
		return (redirection_open_file_error(command, redirection), 0);
	redirection->fd = candidate;
	return (1);
}
