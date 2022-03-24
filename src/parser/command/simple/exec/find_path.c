/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 15:27:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include "parser/parser.h"
#include "env.h"

static int	is_absolute_or_relative(char *path)
{
	return (
		path[0] == '/'
		|| (path[0] == '.' && path[1] == '/')
		|| (path[0] == '.' && path[1] == '.' && path[2] == '/')
	);
}

static int	is_executable_file(t_command *command, char *path, int print_enoent)
{
	struct stat	sb;
	int			stat_result;

	stat_result = stat(path, &sb);
	if (stat_result == -1 && errno != ENOENT)
		return (command_error(command), 0);
	else if (stat_result == -1)
	{
		if (!print_enoent)
			return (0);
		return (command_file_error_errcode(command, errno, 127), 0);
	}
	if (!(sb.st_mode & S_IXUSR))
		return (command_file_error_errcode(command, EACCES, 126), 0);
	else if (S_ISDIR(sb.st_mode))
		return (command_file_error_message(command, "Is a directory"), 0);
	return (S_ISREG(sb.st_mode));
}

static char	*build_pathname(char *path, char *cmd)
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
		else if (is_executable_file(command, candidate, 0))
			return (ft_cmatrix_free(paths), (*path = candidate), 1);
		free(candidate);
		++i;
	}
	return (ft_cmatrix_free(paths), command_not_found_error(command), 0);
}

int	command_find_path(t_command *command, char **path)
{
	char	*user_input;

	if (ft_cmatrix_size(command->argv) == 0)
		return (1);
	user_input = command->argv[0];
	if (is_absolute_or_relative(user_input)
		&& !is_executable_file(command, user_input, 1))
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
