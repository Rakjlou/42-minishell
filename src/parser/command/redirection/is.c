/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 00:08:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

int	redirection_is(t_redirection *redirection, t_redirection_is thing)
{
	if (thing == R_OUT)
	{
		return (token_is(redirection->type, TOK_DGREAT)
			|| token_is(redirection->type, TOK_SGREAT));
	}
	else if (thing == R_IN)
	{
		return (token_is(redirection->type, TOK_DLESS)
			|| token_is(redirection->type, TOK_SLESS));
	}
	else if (thing == R_HERE)
		return (token_is(redirection->type, TOK_DLESS));
	else if (thing == R_IN_SIMPLE)
		return (token_is(redirection->type, TOK_SLESS));
	return (0);
}
