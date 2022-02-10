/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:06:34 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 01:03:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define LEX_TOK_ALLOC_E "minishell lexer:cannot allocate token"
# define LEX_TOK_TEXT_ALLOC_E "minishell lexer:cannot allocate token raw text"
# define LEX_EOF -1

# define AND_IF "&&"
# define OR_IF "||"
# define DLESS "<<"
# define DGREAT ">>"
# define SLESS "<"
# define SGREAT ">"

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
** Definition of supported token types */
typedef enum s_ltoken_type
{
	LTOK_EOF,
	LTOK_TOKEN
}	t_ltoken_type;

/*
** Tokens are the "atoms" of a source, we can see them as words.
** If source is "hello world", tokens will be :
** >>> "hello"
** >>> "world"
*/
typedef struct s_ltoken
{
	t_ltoken_type	type;
	t_lsource		*src;
	char			*raw;
	unsigned long	size;
}	t_ltoken;

typedef struct s_ltoken_candidate
{
	t_ltoken_type	type;
	t_lsource		*src;
	unsigned long	start;
	unsigned long	end;
	unsigned int	delimited;
	unsigned int	is_operator;
	unsigned int	is_word;
	unsigned int	quoting;
	char			quote;
}	t_ltoken_candidate;

t_ltoken	*ltokenize(t_lsource *src);

void		lsource_init(t_lsource *src, char *raw);
void		lsource_incr(t_lsource *src);
char		lsource_getc(t_lsource *src);
char		lsource_prev(t_lsource *src);
char		lsource_next(t_lsource *src);
void		lsource_skip_whitespace(t_lsource *src);

t_ltoken	*ltoken_new(void);
void		ltoken_destroy(t_ltoken *token);
int			ltoken_is_eof(t_ltoken *token);

#endif
