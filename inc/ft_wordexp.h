/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:41:24 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 20:15:23 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WORDEXP_H
# define FT_WORDEXP_H

# define WORDEXP_DEBUG 1

# include <stdlib.h>

typedef struct s_token	t_token;

char	**ft_wordexp(char *str);
char	*paramexp(char *str);
char	**fieldsplit(char *str);

int		get_index_dollar(char *str);
int		get_index_end(char *str, int index_dollar);

char	*get_before_dollar(char *str, int index_dollar);
char	*get_new_dollar_value(char *str, int index_dollar);
char	*get_after_dollar(char *str, int index_dollar);

void	wordexp_debug(char *str, ...);
void	wordexp_print(t_token *token);

#endif
