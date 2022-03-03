/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 21:41:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "lexer/source.h"

typedef enum s_token_type
{
	TOK_EOF,
	TOK_TOKEN,
	TOK_WORD,
	TOK_NAME,
	TOK_IO,
	TOK_AND_IF,
	TOK_OR_IF,
	TOK_O_PARENTHESIS,
	TOK_C_PARENTHESIS,
	TOK_PIPE,
	TOK_SLESS,
	TOK_SGREAT,
	TOK_DLESS,
	TOK_DGREAT
}	t_token_type;

/*
** Tokens are the "atoms" of a source, we can see them as words.
** If source is "hello world", tokens will be :
** >>> "hello"
** >>> "world"
*/
typedef struct s_token
{
	t_token_type	type;
	t_source		*src;
	char			*raw;
	char			**expanded;
	unsigned long	size;
}	t_token;

t_token		*token_recognizer(t_source *src);

t_token		*token_new(void);
void		token_destroy(t_token *token);
void		token_vdestroy(void *token);

int			token_is_redirection_operator(t_token *token);
int			token_is_invalid_command_start(t_token *token);
int			token_is(t_token *token, t_token_type type);
int			token_raw_is(t_token *token, char *text);
int			token_is_eof(t_token *token);

#endif
