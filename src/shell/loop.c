/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 18:55:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftprintf.h"
#include "input.h"
#include "shell.h"
#include "env.h"
#include "parser/parser.h"
#include "built_in.h"

void	shell_loop(void)
{
	char	*line;

	while (42)
	{
		line = input_get_line();
		if (line == NULL)
		{
			ftfprintf(STDERR_FILENO, "exit\n");
			break ;
		}
		parser_init(line);
		parser_execute();
		parser_destroy();
	}
}
