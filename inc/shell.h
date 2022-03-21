/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:10:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/21 19:03:50 by nsierra-         ###   ########.fr       */
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

typedef struct s_exec
{
	int	pipeline;
	int	pipe_in;
	int	pipe_out;
}	t_exec;

typedef struct s_shell
{
	t_shell_param	param;
	t_parser		parser;
	t_env			env;
	t_exec			exec;
	t_command		*last_command;
}	t_shell;

t_shell	*_shell(void);
int		_last_command_status(void);

int		shell_init(int argc, char **argv);
void	shell_destroy(void);
void	shell_loop(void);
int		signals_init(void);

#endif
