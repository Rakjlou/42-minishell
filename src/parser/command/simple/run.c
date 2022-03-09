/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 04:21:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftprintf.h"
#include "wordexp.h"
#include "env.h"
#include "shell.h"
#include "built_in.h"
#include "parser/parser.h"

static void	command_error(t_command *command)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s\n",
		"minishell",
		strerror(errno));
}

static void	command_file_error_errcode(t_command *command, int errcode)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		strerror(errcode));
}

static void	command_file_error_message(t_command *command, char *message)
{
	command->status = EXIT_FAILURE;
	ftfprintf(
		STDERR_FILENO,
		"%s: %s: %s\n",
		"minishell",
		command->argv[0],
		message);
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
	char			**tmp;

	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		arg->expanded = wordexp(arg->raw);
		if (arg->expanded == NULL)
			return (build_argv_error(command), 0);
		tmp = command->argv;
		command->argv = ft_cmatrix_join(command->argv, arg->expanded);
		if (command->argv == NULL)
			return (ft_cmatrix_free(tmp), build_argv_error(command), 0);
		ft_cmatrix_free(tmp);
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
	if (!ft_strncmp(command->argv[0], "echo", -1))
		command->status = bi_echo(command->argv);
	else if (!ft_strncmp(command->argv[0], "cd", -1))
		command->status = bi_cd(command->argv);
	else if (!ft_strncmp(command->argv[0], "pwd", -1))
		command->status = bi_pwd(command->argv);
	else if (!ft_strncmp(command->argv[0], "export", -1))
		command->status = bi_export(command->argv);
	else if (!ft_strncmp(command->argv[0], "unset", -1))
		command->status = bi_unset(command->argv);
	else if (!ft_strncmp(command->argv[0], "env", -1))
		command->status = bi_env(command->argv);
	else if (!ft_strncmp(command->argv[0], "exit", -1))
		command->status = bi_exit(command->argv);
}

static int	is_absolute_or_relative(char *path)
{
	return (
		path[0] == '/'
		|| (path[0] == '.' && path[1] == '/')
		|| (path[0] == '.' && path[1] == '.' && path[1] == '/')
	);
}

static int	is_executable_file(t_command *command, char *path)
{
	struct stat	sb;
	int			stat_result;

	stat_result = stat(path, &sb);
	if (stat_result == -1 && errno != ENOENT)
		return (command_error(command), 0);
	else if (stat_result == -1)
		return (0);
	if (!(sb.st_mode & S_IXUSR))
		return (command_file_error_errcode(command, EACCES), 0);
	else if (!S_ISREG(sb.st_mode))
		return (command_file_error_message(command, "Is a directory"), 0);
	return (1);
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
	while (paths[i] && command->status == EXIT_SUCCESS)
	{
		candidate = build_pathname(paths[i], command->argv[0]);
		if (candidate == NULL)
			return (ft_cmatrix_free(paths), command_error(command), 0);
		else if (is_executable_file(command, candidate))
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
	if (is_absolute_or_relative(user_input)
		&& !is_executable_file(command, user_input))
		return (0);
	else if (is_absolute_or_relative(user_input))
	{
		*path = ft_strdup(user_input);
		if (*path == NULL)
			return (command_error(command), 0);
		return (1);
	}
	return (command_find_path_in_env(command, path));
}

static void	command_exec(t_command *command)
{
	char	*path;
	pid_t	child_pid;

	if (command->status != EXIT_SUCCESS || !command_find_path(command, &path))
		return ;
	child_pid = fork();
	if (child_pid == -1)
		return (command_error(command));
	else if (child_pid == 0)
		execve(path, command->argv, _shell()->param.env);
	else
	{
		waitpid(child_pid, NULL, 0);
		free(path);
	}
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
