/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/21 21:06:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "parser/parser.h"
#include "adrian/test.h"

int	main(int argc, char **argv)
{
	char		*input;


	init_arg_main(argc, argv);
	handle_signal();
	while (42)
	{
		input = readline("$ ");
		if (input == NULL)
			break ;
		test(input);
		//lexer_execute(line);
		free(input);
	}
	return (0);
}
