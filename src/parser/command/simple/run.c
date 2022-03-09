/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 02:27:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "ftprintf.h"
#include "wordexp.h"
#include "env.h"
#include "parser/parser.h"

static void	build_argv_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	perror("minishell");
}

static int	build_argv(t_command *command)
{
	t_lst			*args;
	t_iter			iter;
	t_token			*arg;

	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		arg->expanded = wordexp(arg->raw);
		if (arg->expanded == NULL)
			return (build_argv_error(command), 0);
		command->argv = ft_cmatrix_join(command->argv, arg->expanded);
		if (command->argv == NULL)
			return (build_argv_error(command), 0);
	}
	return (1);
}

static int	is_builtin(char *str)
{
	char	*builtins[7];
	int		i;

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	i = 0;
	while (i < 7)
	{
		if (!ft_strncmp(builtins[i], str, -1))
			return (1);
		++i;
	}
	return (0);
}

static void	builtin_exec(t_command *command)
{
	ftprintf("Executing builtin %s\n", command->argv[0]);
}

static int	is_absolute_or_relative(char *path)
{
	return (
		path[0] == '/'
		|| (path[0] == '.' && path[1] == '/')
		|| (path[0] == '.' && path[1] == '.' && path[1] == '/')
	);
}

static int	is_executable(char *path)
{
	return (access(path, X_OK) == 0);
}

static void	command_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s\n",
		"minishell",
		strerror(errno));
}

static void	command_find_path_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		strerror(errno));
}

static void	command_not_found_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		"command not found");
}

char	*build_pathname(char *path, char *cmd)
{
	char	*tmp;
	char	*result;
	size_t	len;

	result = ft_strdup(path);
	if (result == NULL)
		return (NULL);
	len = ft_strlen(result);
	if (len > 0 && result[len - 1] != '/')
	{
		tmp = result;
		result = ft_strjoin(result, "/");
		if (result == NULL)
			return (free(tmp), NULL);
		free(tmp);
	}
	tmp = result;
	result = ft_strjoin(result, cmd);
	if (result == NULL)
		return (free(tmp), NULL);
	return (free(tmp), result);
}

static int	command_find_path_in_env(t_command *command, char **path)
{
	int		i;
	char	*env_path;
	char	*candidate;
	char	**paths;

	env_path = env_get_value("PATH");
	if (env_path == NULL)
		return (command_not_found_error(command), 0);
	paths = ft_split(env_path, ":");
	if (paths == NULL)
		return (command_error(command), 0);
	else if (ft_cmatrix_size(paths) == 0)
		return (ft_cmatrix_free(paths), command_not_found_error(command), 0);
	i = 0;
	while (paths[i])
	{
		candidate = build_pathname(paths[i], command->argv[0]);
		if (candidate == NULL)
			return (ft_cmatrix_free(paths), command_error(command), 0);
		else if (is_executable(candidate))
			return (ft_cmatrix_free(paths), (*path = candidate), 1);
		free(candidate);
		++i;
	}
	return (ft_cmatrix_free(paths), command_not_found_error(command), 0);
}

static int	command_find_path(t_command *command, char **path)
{
	char	*user_input;

	user_input = command->argv[0];
	if (is_absolute_or_relative(user_input) && !is_executable(user_input))
		return (command_find_path_error(command), 0);
	else if (is_absolute_or_relative(user_input))
		return ((*path = user_input), 1);
	return (command_find_path_in_env(command, path));
}

static void	command_exec(t_command *command)
{
	char	*path;

	if (!command_find_path(command, &path))
		return ;
	ftprintf("FOUND %s\n", path);
	free(path);
}

static void	command_simple_exec(t_command *command)
{
	if (command->status != 0
		|| !build_argv(command)
		|| ft_cmatrix_size(command->argv) == 0)
		return ;
	else if (is_builtin(command->argv[0]))
		builtin_exec(command);
	else
		command_exec(command);
}

void	command_simple_run(t_command *command)
{
	redirections_run(command, &command->data.simple.redirections);
	command_simple_exec(command);
	redirections_stop(&command->data.simple.redirections);
}
