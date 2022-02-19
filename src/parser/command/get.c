/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/02/19 01:26:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

t_lst	*command_get_redirections(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		return (&command->data.simple.redirections);
	return (NULL);
}

t_lst	*command_get_args(t_command *command)
{
	if (command->type == COMMAND_SIMPLE)
		return (&command->data.simple.args);
	return (NULL);
}
