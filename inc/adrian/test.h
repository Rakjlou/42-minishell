/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:17:56 by ajung             #+#    #+#             */
/*   Updated: 2022/02/21 17:02:31 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>



// typedef void (*sighandler_t)(int);

//sighandler_t	handle_signal();


typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**env;
}	t_args;

typedef struct s_shell 
{
	t_args	args;
	int		last_status;

}	t_shell;

void			init_arg_main(int argc, char **argv);
void			test(char *input);
t_shell			*_shell(void);
int				handle_signal();





#endif
