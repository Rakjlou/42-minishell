/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 04:24:27 by nsierra-         ###   ########.fr       */
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
	char	*line;
	char	*line_trimmed;

	line = readline(PS1_DEFAULT);
	if (line == NULL || !*line)
		return (line);
	line_trimmed = ft_strtrim(line, " \t\n\r\v\f");
	if (line_trimmed == NULL)
		return (input_save_line_to_history(line));
	free(line);
	return (input_save_line_to_history(line_trimmed));
}
