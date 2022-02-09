/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:06:34 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/09 00:36:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

# define UI_TOK_ALLOC_E "minishell lexer:cannot allocate token"
# define UI_TOK_TEXT_ALLOC_E "minishell lexer:cannot allocate token raw text"
# define UI_EOF -1

typedef struct s_user_input
{
	char			*raw;
	unsigned long	size;
	unsigned long	cursor;
}	t_user_input;

typedef struct s_token
{
	t_user_input	*ui;
	char			*raw;
	unsigned long	size;
}	t_token;

void	ui_init(t_user_input *ui, char *raw);
char	ui_next(t_user_input *ui);
void	ui_rewind(t_user_input *ui);
char	ui_peek(t_user_input *ui);
void	ui_skip_whitespace(t_user_input *ui);

t_token	*ui_tokenize(t_user_input *ui);
void	ui_token_destroy(t_token *token);
int		ui_token_is_eof(t_token *token);

#endif
