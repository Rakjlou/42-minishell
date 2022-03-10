/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:53:20 by ajung             #+#    #+#             */
/*   Updated: 2022/03/10 14:59:21 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "shell.h"

int	bi_pwd(char **arg)
{
	char	douille[10000];

	(void) arg;
	getcwd(douille, 10000);
	ft_putstr_fd(douille, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	env_set_value("PWD", douille);
	return (EXIT_SUCCESS);
}
