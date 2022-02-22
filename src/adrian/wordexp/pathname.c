/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:51:00 by ajung             #+#    #+#             */
/*   Updated: 2022/02/22 20:32:40 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adrian/test.h"

char *pathname_exp(char *str)
{
	(void) str;
	int	i;
// 	Si IFS est set
// 	--> return ;
	i = 0;
	while (str[i] != '*' && str[i])
		i++;
	while  (str[i] == '*')
		i++;
	//On est sur le char apres les **
}
