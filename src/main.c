/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 18:50:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "parser/parser.h"
#include "adrian/test.h"

int	main(int argc, char **argv)
{
	char		*line;

	init_arg_main(argc, argv);
	env_init();
	handle_signal();
	while (42)
	{
		line = input_get_line();
		if (line == NULL)
			break ;
		parser_execute(line);
		free(line);
	}
	input_clear();
	env_free(&_shell()->env);
	return (0);
}
