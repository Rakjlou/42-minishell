/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:41:24 by ajung             #+#    #+#             */
/*   Updated: 2022/03/02 20:31:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "ftlst.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_env_content
{
	char	*key;
	char	*value;
}	t_env_content;

typedef t_lst	t_env;

t_env			*_env(void);

int				env_init(void);
char			*env_get_value(char *key);
t_env_content	*env_get_content(char *key);
int				env_set_value(char *key, char *value);
void			env_unset(char *key);
void			env_free(void);
void			env_print(void);
void			env_print_export(void);
void			env_content_destroy(t_env_content *content);

t_env_content	*env_content_new(char *key, char *value);

#endif
