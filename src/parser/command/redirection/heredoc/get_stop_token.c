/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stop_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/25 17:08:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wordexp.h"
#include "parser/parser.h"

static char	**get_raw(t_redirection *redirection)
{
	char	*raw;
	char	**matrix;

	raw = redirection->arg->raw;
	matrix = ft_calloc(sizeof(char *), 2);
	if (matrix == NULL)
		return (NULL);
	matrix[0] = ft_strdup(raw);
	if (matrix[0] == NULL)
		return (free(matrix), NULL);
	return (matrix);
}

char	*heredoc_get_stop_token(t_redirection *redirection)
{
	char	**raw;
	char	**unquoted;
	char	*token;

	raw = get_raw(redirection);
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
