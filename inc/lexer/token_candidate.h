/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_candidate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:22:27 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/11 02:11:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_CANDIDATE_H
# define TOKEN_CANDIDATE_H

# include "lexer/source.h"

# include "tokens.h"

typedef struct s_token_candidate
{
	t_source		*src;
	unsigned long	start;
	unsigned long	end;
	unsigned int	delimited;
	unsigned int	is_operator;
	unsigned int	is_word;
	unsigned int	quoting;
	char			quote;
}	t_token_candidate;

void	token_candidate_init(t_source *src, t_token_candidate *candidate);
void	token_candidate_incr(t_token_candidate *candidate);
void	token_candidate_consume_name(t_token_candidate *candidate);
char	*token_candidate_text(t_token_candidate *c, int s_offset, int l_offset);

int		token_candidate_is_quote(t_token_candidate *candidate);
int		token_candidate_is_unquoted_param(t_token_candidate *candidate);
int		token_candidate_is_unquoted_space(t_token_candidate *candidate);
void	token_candidate_handle_quote(t_token_candidate *candidate);

int		token_candidate_is_part_of_operator(t_token_candidate *candidate);
int		token_candidate_is_end_of_operator(t_token_candidate *candidate);
int		token_candidate_is_start_of_operator(t_token_candidate *candidate);

#endif
