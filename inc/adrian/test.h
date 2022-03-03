/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:17:56 by ajung             #+#    #+#             */
/*   Updated: 2022/03/03 16:52:55 by ajung            ###   ########.fr       */
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
# include <sys/types.h>
# include <dirent.h>
# include "env.h"
# include "ftlst.h"

# define OPEN 1
# define CLOSE 0

# define SINGLE 1
# define DOUBLE 2


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
	t_lst	env;
	t_args	args;
	int		last_status;

}	t_shell;

void			init_arg_main(int argc, char **argv);
void			test(char *input);
t_shell			*_shell(void);
int				handle_signal();

/* WORD_EXPANSION */
char	**fieldsplit(char *str);

void	perror_exit();

/*PARAM_EXPANSION*/
char	*paramexp(char *str);

/*get_index*/
int	get_index_dollar(char *str);
int	get_index_end(char *str, int index_dollar);

/*get_dollar_str*/
char	*get_before_dollar(char *str, int index_dollar);
char	*get_new_dollar_value(char *str, int index_dollar);
char	*get_after_dollar(char *str, int index_dollar);

/*UNQUOTING*/
char	**unquoting(char **str);





#endif
