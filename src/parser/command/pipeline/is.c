/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/23 18:53:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	pipeline_is_active(void)
{
	return (_shell()->pipeline.r > 0);
}

int	pipeline_is_first(void)
{
	return (_shell()->pipeline.l == 1 && _shell()->pipeline.r == 1);
}

int	pipeline_is_middle(void)
{
	return (_shell()->pipeline.l == 1 && _shell()->pipeline.r == 2);
}

int	pipeline_is_last(void)
{
	return (_shell()->pipeline.l == 0 && _shell()->pipeline.r == 1);
}
