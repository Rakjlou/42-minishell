/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:34:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "minishell.h"

int	main(void)
{
	char		*line;
	t_lsource	ui;
	t_ltoken	*token;

	while (42)
	{
		line = readline(PS1_DEFAULT);
		if (line == NULL)
			break ;
		lsource_init(&ui, line);
		while (42)
		{
			token = ltokenize(&ui);
			if (token == NULL)
				break ;
			else if (ltoken_is_eof(token))
			{
				ltoken_destroy(token);
				break ;
			}
			ltoken_destroy(token);
		}
		free(line);
	}
	return (0);
}
