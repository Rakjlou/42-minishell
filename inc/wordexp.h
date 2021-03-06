/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:41:24 by ajung             #+#    #+#             */
/*   Updated: 2022/03/28 22:24:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDEXP_H
# define WORDEXP_H

# define QUOTE_STATUS_CLOSE 0
# define QUOTE_STATUS_OPEN 1

# define DETECTED 1
# define UNDETECTED 0
# define WORDEXP_DEBUG 0

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_token	t_token;
typedef struct dirent	t_dirent;

char	**wordexp(char *str);
char	*paramexp(char *str);
char	**fieldsplit(char *str);

int		get_index_dollar(char *str);
int		get_index_end(char *str, int index_dollar);

char	*get_before_dollar(char *str, int index_dollar);
char	*get_new_dollar_value(char *str, int index_dollar);
char	*get_after_dollar(char *str, int index_dollar);

char	**unquoting(char **str);

char	**pathname_exp(char	**arg);

char	**glob(char **matrix);

//A DELETE
void	wordexp_debug(char *str, ...);
void	wordexp_print(t_token *token);
void	debug(char **unquote_output);

#endif
