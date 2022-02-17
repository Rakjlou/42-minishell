/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/17 20:36:11 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "lexer/lexer.h"
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
		lexer_execute(line);
		free(line);
	}
	return (0);
}
