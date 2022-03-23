/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:10:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 18:42:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"
# include "parser/parser.h"

typedef struct s_shell_param
{
	int				argc;
	char			**argv;
	char			**env;
}	t_shell_param;

typedef struct s_pipeline
{
	int	pipe_in;
	int	pipe_out;
	int	l;
	int	r;
}	t_pipeline;

typedef struct s_shell
{
	t_shell_param	param;
	t_parser		parser;
	t_env			env;
	t_pipeline		pipeline;
	t_command		*last_command;
	int				last_command_status;
}	t_shell;

t_shell	*_shell(void);
int		_last_command_status(void);

int		shell_init(int argc, char **argv);
void	shell_destroy(void);
void	shell_loop(void);
int		signals_init(void);

#endif
