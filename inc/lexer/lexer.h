/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/11 01:59:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ftlst.h"
# include "lexer/source.h"
# include "lexer/token.h"

typedef enum e_lexer_status
{
	LEXER_STATUS_DEFAULT,
	LEXER_STATUS_ERROR,
	LEXER_SYNTAX_ERROR,
	LEXER_UNEXPECTED_TOK_ERROR,
	LEXER_STATUS_TOTAL
}	t_lexer_status;

typedef struct s_lexer
{
	t_lexer_status	status;
	t_source		src;
	t_lst			tokens;
}	t_lexer;

void	lexer_execute(char *line);

#endif
