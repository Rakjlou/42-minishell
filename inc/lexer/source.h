/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:45:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# define SOURCE_EOF -1

/*
** Lexer sources are just structs allowing to navigate through a string
** character by character
*/
typedef struct s_source
{
	char			*raw;
	unsigned long	size;
	unsigned long	cursor;
}	t_source;

void		source_init(t_source *src, char *raw);
void		source_incr(t_source *src);
char		source_getc(t_source *src);
char		source_prev(t_source *src);
char		source_next(t_source *src);
void		source_skip_whitespace(t_source *src);

#endif
