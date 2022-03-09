/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:45:36 by ajung             #+#    #+#             */
/*   Updated: 2022/03/08 20:48:22 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

/* 
Ex: INPUT USER: echo -n "Aloha"
Je recois:
echo 
-n 
Aloha 

minishell$ echo -n
start arg 1
FLAG -n NOT detected
-n

minishell$ echo -xxxxxxxxxxxxxxxxx "bonjour"
start arg 2
FLAG -n detected

*/
static int start_arg(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 1;
		while (arg[i][j] && arg[i][0] == '-' && arg[i][j] == 'n')
			j++;
		i++;
	}
	if (i > 1)
		i--;
	return (i);

}

int	bi_echo(char **arg)
{
	int	i;

	i = start_arg(arg);
	dprintf(2, "start arg %d\n", i);
		//DEBUG A ENLEVER
	if (start_arg(arg) == 1 && BUILT_IN_DEBUG == 1)
		dprintf(2, "FLAG -n NOT detected\n");
	else if (start_arg(arg) != 1 && BUILT_IN_DEBUG == 1)
		dprintf(2, "FLAG -n detected\n");
	while (arg[i])
		ft_putstr_fd(arg[i++], STDOUT_FILENO);
	if (start_arg(arg) == 1)
		ft_putstr_fd("\n", STDOUT_FILENO);

	return (EXIT_SUCCESS);
}
