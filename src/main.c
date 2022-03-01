/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/01 18:57:31 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include "parser/parser.h"
#include "adrian/test.h"

int	main(int argc, char **argv)
{
	char		*input;

	init_arg_main(argc, argv);
	env_init();
	handle_signal();
	while (42)
	{
		input = readline("$ ");
		if (input == NULL)
			break ;
		parser_execute(input);
		test(input);
		free(input);
	}
	return (0);
}
