/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:45:54 by ajung             #+#    #+#             */
/*   Updated: 2022/03/09 04:17:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# define BUILT_IN_DEBUG 1

# include <stddef.h>
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	bi_cd(char **arg);
int	bi_echo(char **arg);
int	bi_env(char **arg);
int	bi_exit(char **arg);
int	bi_export(char **arg);
int	bi_pwd(char **arg);
int	bi_unset(char **arg);

//A ENLEVER
void	bi_debug(char *str);

#endif
