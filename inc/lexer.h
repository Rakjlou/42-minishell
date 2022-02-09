/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:06:34 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 01:31:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define LEX_TOK_ALLOC_E "minishell lexer:cannot allocate token"
# define LEX_TOK_TEXT_ALLOC_E "minishell lexer:cannot allocate token raw text"
# define LEX_EOF -1

/*
** Lexer sources are just structs allowing to navigate through a string
** character by character
*/
typedef struct s_lsource
{
	char			*raw;
	unsigned long	size;
	unsigned long	cursor;
}	t_lsource;

/*
** Tokens are the "atoms" of a source, we can see them as words.
** If source is "hello world", tokens will be :
** >>> "hello"
** >>> "world"
*/
typedef struct s_ltoken
{
	t_lsource		*ui;
	char			*raw;
	unsigned long	size;
}	t_ltoken;

void		lsource_init(t_lsource *src, char *raw);
char		lsource_next(t_lsource *src);
char		lsource_peek(t_lsource *src);
void		lsource_skip_whitespace(t_lsource *src);

t_ltoken	*ltoken_new(void);
t_ltoken	*ltokenize(t_lsource *src);
void		ltoken_destroy(t_ltoken *token);
int			ltoken_is_eof(t_ltoken *token);

#endif
