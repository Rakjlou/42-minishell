/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:02:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"
#include "minishell.h"

int	main(void)
{
	char			*line;
	t_user_input	ui;
	t_token			*token;

	while (42)
	{
		line = readline(PS1_DEFAULT);
		if (line == NULL)
			break ;
		ui_init(&ui, line);
		while (42)
		{
			token = ui_tokenize(&ui);
			if (token == NULL)
				break ;
			else if (ui_token_is_eof(token))
			{
				ui_token_destroy(token);
				break ;
			}
			printf(">>>%s\n", token->raw);
			ui_token_destroy(token);
		}
		free(line);
	}
	return (0);
}
