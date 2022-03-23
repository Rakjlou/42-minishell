/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:53:47 by ajung             #+#    #+#             */
/*   Updated: 2022/03/23 19:56:09 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "shell.h"
#include "libft/ftprintf.h"
/* 
CHEMIN RELATIF ET ABSOLU
ex:
cd 
libft/blabla

cd tout seul */

/* 
int access(const char *pathname, int mode);
F OK --> si fichier existe

 */

static void	too_many_args(char **arg)
{
	t_shell	*shell;

	shell = _shell();
	ftfprintf(STDERR_FILENO, "%s: %s: %s\n",
		"minishell",
		arg[0],
		"too many arguments");
	shell->last_command_status = 1;
}

static void	update_pwd(void)
{
	char	douille[PATH_MAX];

	getcwd(douille, PATH_MAX);
	env_set_value("PWD", douille);
}

static void	update_old_pwd(void)
{
	env_set_value("OLDPWD", env_get_value("PWD"));
}

static void	invalid_path(char **arg)
{
	t_shell	*shell;

	shell = _shell();
	ftfprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
		"minishell",
		arg[0],
		arg[1],
		"No such file or directory");
	shell->last_command_status = 1;
}

int	bi_cd(char **arg)
{
	int	size;

	size = ft_cmatrix_size(arg);
	if (size > 2)
		return (too_many_args(arg), EXIT_SUCCESS);
	if (size == 2 && access(arg[1], F_OK) < 0)
		return (invalid_path(arg), EXIT_SUCCESS);
	if (size == 1)
		chdir(getenv("HOME"));
	else
		chdir(arg[1]);
	update_old_pwd();
	update_pwd();
	return (EXIT_SUCCESS);
}
