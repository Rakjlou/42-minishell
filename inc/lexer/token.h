/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/10 02:47:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "lexer/source.h"

/*
** Tokens are the "atoms" of a source, we can see them as words.
** If source is "hello world", tokens will be :
** >>> "hello"
** >>> "world"
*/
typedef struct s_token
{
	t_source		*src;
	char			*raw;
	unsigned long	size;
}	t_token;

t_token		*tokenize(t_source *src);

t_token		*token_new(void);
void		token_destroy(t_token *token);
int			token_is_eof(t_token *token);

#endif
