/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 04:21:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "env.h"
#include "parser/parser.h"
#include "built_in.h"

void	shell_loop(void)
{
	char		*line;

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
