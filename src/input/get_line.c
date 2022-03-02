/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 06:02:46 by nsierra-         ###   ########.fr       */
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

char	*input_get_line(void)
{
	return (input_get_line_prompt(PS1_DEFAULT));
}

char	*input_get_line2(void)
{
	return (readline(PS2_DEFAULT));
}

char	*input_get_line_prompt(char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (line == NULL || !*line)
		return (line);
	return (input_save_line_to_history(line));
}
