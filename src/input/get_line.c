/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 18:37:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "input.h"

static char	*input_save_line_to_history(char *line)
{
	add_history(line);
	return (line);
}

static char	*input_get_line_prompt(char *prompt, int history_save)
{
	char	*line;

	line = readline(prompt);
	if (!history_save || line == NULL || !*line)
		return (line);
	return (input_save_line_to_history(line));
}

char	*input_get_line(void)
{
	return (input_get_line_prompt(PS1_DEFAULT, 1));
}

char	*input_get_line2(void)
{
	return (input_get_line_prompt(PS2_DEFAULT, 0));
}
