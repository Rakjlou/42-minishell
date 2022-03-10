/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:23:14 by ajung             #+#    #+#             */
/*   Updated: 2022/03/09 20:53:25 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

t_shell	*_shell(void)
{
	static t_shell	shell;
	static int		check = 0;

	if (check == 0)
	{
		check = 1;
		ft_bzero(&shell, sizeof(t_shell));
	}
	return (&shell);
}

t_env	*_env(void)
{
	t_shell	*shell;

	shell = _shell();
	return (&shell->env);
}

t_parser	*_parser(void)
{
	t_shell	*shell;

	shell = _shell();
	return (&shell->parser);
}
