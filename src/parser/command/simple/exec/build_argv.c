/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 20:23:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "wordexp.h"

int	command_build_argv(t_command *command)
{
	t_lst			*args;
	t_iter			iter;
	t_token			*arg;
	char			**tmp;

	args = &command->data.simple.args;
	iter_init(&iter, args, ASC);
	while (iter_next(&iter))
	{
		arg = iter.data;
		arg->expanded = wordexp(arg->raw);
		if (arg->expanded == NULL)
			return (build_argv_error(command), 0);
		tmp = command->argv;
		command->argv = ft_cmatrix_join(command->argv, arg->expanded);
		if (command->argv == NULL)
			return (ft_cmatrix_free(tmp), build_argv_error(command), 0);
		ft_cmatrix_free(tmp);
	}
	return (1);
}
