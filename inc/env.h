/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:41:24 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 18:33:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include "ftprintf.h"
# include "ftlst.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_env_content
{
	char	*key;
	char	*value;
}	t_env_content;

char	*env_get_value(t_lst *env, char *key);
int		env_set_value(t_lst *env, char *key, char *value);
void	env_unset(t_lst *env, char *key);
void	env_free(t_lst *env);
void	env_print(t_lst *env);
void	env_print_export(t_lst *env);
void	env_content_destroy(t_env_content *content);
int		env_init(void);
t_env_content	*env_content_new(char *key, char *value);


/*
export est trie par ordre alphabetique
 */
#endif
