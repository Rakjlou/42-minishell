/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 20:43:05 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
			break ;
		parser_execute(line);
		free(line);
	}
	input_clear();
	env_free();
}
