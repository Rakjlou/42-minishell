/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 18:07:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "wordexp.h"
#include "parser/parser.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static char	**str_as_matrix(char *raw)
{
	char	**matrix;

	if (raw == NULL)
		return (NULL);
	matrix = ft_calloc(sizeof(char *), 2);
	if (matrix == NULL)
		return (NULL);
	matrix[0] = ft_strdup(raw);
	if (matrix[0] == NULL)
		return (free(matrix), NULL);
	return (matrix);
}

char	**redirection_wordexp(char *raw)
{
	char	*paramexp_output;
	char	**paramexp_matrix;
	char	**unquoted;

	paramexp_output = paramexp(raw);
	if (paramexp_output == NULL)
		return (NULL);
	paramexp_matrix = str_as_matrix(paramexp_output);
	if (paramexp_matrix == NULL)
		return (free(paramexp_output), NULL);
	unquoted = unquoting(paramexp_matrix);
	if (unquoted == NULL)
		return (free(paramexp_output), ft_cmatrix_free(paramexp_matrix), NULL);
	free(paramexp_output);
	ft_cmatrix_free(paramexp_matrix);
	return (unquoted);
}

char	*heredoc_wordexp(t_redirection *redirection)
{
	char	**raw;
	char	**unquoted;
	char	*token;

	raw = str_as_matrix(redirection->arg->raw);
	if (raw == NULL)
		return (NULL);
	unquoted = unquoting(raw);
	if (unquoted == NULL)
		return (ft_cmatrix_free(raw), NULL);
	token = ft_strdup(unquoted[0]);
	if (token == NULL)
	{
		return (
			ft_cmatrix_free(raw),
			ft_cmatrix_free(unquoted),
			NULL
		);
	}
	ft_cmatrix_free(raw);
	ft_cmatrix_free(unquoted);
	return (token);
}
