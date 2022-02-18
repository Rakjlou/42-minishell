/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/18 20:47:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "parser/parser.h"
#include "adrian/test.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;

	init_arg_main(argc, argv);
	while (42)
	{
		line = readline("$ ");
		if (line == NULL)
			break ;
		test(line);
		parser_execute(line);
		free(line);
	}
	return (0);
}
