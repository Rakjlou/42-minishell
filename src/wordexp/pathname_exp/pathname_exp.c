/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:59:57 by ajung             #+#    #+#             */
/*   Updated: 2022/03/21 21:34:48 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordexp.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"


# define DETECTED 1
# define UNDETECTED 0


static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	get_size_dir(void)
{
	DIR		*DIR;
	int		size_dir;

	size_dir = 0;
	DIR = opendir(".");
	if (!DIR)
		return (EXIT_FAILURE);
	while(!readdir(DIR))
		size_dir++;
	return (size_dir);
}


char	**get_dir(int dot_flag)
{
	char			**output;
	DIR				*dir;
	struct dirent	*dir_name;
	int				i;

	if (get_size_dir() == EXIT_FAILURE)
		return (NULL);
	output = ft_calloc(get_size_dir(), sizeof(char *));
	if (!output)
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (NULL);
	dir_name = readdir(dir);
	i = 0;
	while (!dir_name)
	{
		if ((dot_flag = DETECTED && dir_name->d_name[0] == '.')
			|| (dot_flag == UNDETECTED && dir_name->d_name[0] != '.'))
		{
			output[i] = ft_strdup(dir_name->d_name);
			if (!output[i])
				return (ft_free_split(output), NULL);
			i++;
		}
		dir_name = readdir(dir);
	}
	return (output);
}

int	detect_dot(char *str)
{
	if (str[0] == '.')
		return (DETECTED);
	return (UNDETECTED);	
}

int	detect_wildcard(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (DETECTED);
	}
	return (UNDETECTED);
}

char	**expand_str(char *str)
{
	char	**dir;
	char	**expanded;
	int		i;
	int		j;
	char	**to_find;

	if (detect_wildcard(str) == UNDETECTED)
		return (ft_split(str, "")); //a changer, ne pas rentrer si no *
	dir = get_dir(detect_dot(str));
	

}


char	**pathname_exp(char	**arg)
{
	char	**dir;
	char	**output;

	

	return (output);
}
