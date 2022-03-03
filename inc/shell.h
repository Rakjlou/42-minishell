/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:10:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 21:30:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"

typedef struct s_shell_param
{
	int		argc;
	char	**argv;
	char	**env;
}	t_shell_param;

typedef struct s_shell
{
	t_shell_param	param;
	t_env			env;
}	t_shell;

t_shell	*_shell(void);

int		shell_init(int argc, char **argv);
void	shell_loop(void);
int		signals_init(void);

#endif
