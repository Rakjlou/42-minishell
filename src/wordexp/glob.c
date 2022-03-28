/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:59:31 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 22:25:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <dirent.h>
#include "ftlst.h"
#include "ftprintf.h"

static bool	glob_is_a_match_finish(char *request, char *candidate, int i, int j)
{
	char	stop;

	stop = request[i - 1];
	while (candidate[j])
		j++;
	if (j > 0 && stop == candidate[j - 1])
		return (true);
	return (request[i + 1] == '\0' && candidate[j + 1] == '\0');
}

static bool	glob_is_a_match(char *request, char *candidate, int j, int i)
{
	char	stop;

	while (request[i])
	{
		if (request[i] == '*')
		{
			if (request[i + 1] == '*' && ++i)
				continue ;
			stop = request[i + 1];
			if (stop == '\0')
				return (true);
			while (candidate[j] != stop && candidate[j])
				++j;
			if (!candidate[j])
				return (false);
			++i;
		}
		else if (request[i] != candidate[j])
			return (false);
		else if (++i && ++j)
			continue ;
	}
	return (glob_is_a_match_finish(request, candidate, i, j));
}

static bool	glob_loop(char *str, DIR *directory, t_lst *result)
{
	int				old_errno;
	char			*filename;
	t_dirent		*current;

	while (42)
	{
		old_errno = errno;
		current = readdir(directory);
		if (current == NULL)
		{
			if (errno != old_errno)
				return (false);
			break ;
		}
		else if (glob_is_a_match(str, current->d_name, 0, 0))
		{
			filename = ft_strdup(current->d_name);
			if (filename == NULL)
				return (false);
			lst_push_back(result, filename);
		}
	}
	return (true);
}

static bool	glob_execute(char *str, t_lst *result)
{
	DIR		*directory;
	bool	ok;

	directory = opendir(".");
	if (directory == NULL)
		return (false);
	ok = glob_loop(str, directory, result);
	closedir(directory);
	return (ok);
}

char	**glob(char **matrix)
{
	t_lst	result;
	char	*dup;
	char	**result_matrix;
	int		i;

	i = 0;
	ft_bzero(&result, sizeof(t_lst));
	while (matrix && matrix[i])
	{
		if (!ft_strchr(matrix[i], '*') || ft_strchr(matrix[i], '\'')
			|| ft_strchr(matrix[i], '\"'))
		{
			dup = ft_strdup(matrix[i]);
			if (dup == NULL)
				return (lst_destroy_nodes(&result, free), NULL);
			(lst_push_back(&result, dup), ++i);
			continue ;
		}
		else if (!glob_execute(matrix[i], &result))
			return (lst_destroy_nodes(&result, free), NULL);
		++i;
	}
	result_matrix = lst_as_cmatrix(&result, 0);
	lst_destroy_nodes(&result, NULL);
	return (result_matrix);
}
