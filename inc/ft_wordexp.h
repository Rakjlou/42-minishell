/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:41:24 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 19:14:44 by nsierra-         ###   ########.fr       */
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

void	wordexp_debug(char *str, ...);
void	wordexp_print(t_token *token);

#endif
