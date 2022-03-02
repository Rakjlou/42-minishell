/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:10:59 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/02 17:15:53 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <readline/readline.h>
# include <readline/history.h>

# define PS1_DEFAULT "\x1b[32mminishell$ \x1b[0m"
# define PS2_DEFAULT "\x1b[33m> \x1b[0m"

char	*input_get_line(void);
char	*input_get_line2(void);
char	*input_get_line_prompt(char *prompt);
void	input_clear(void);

#endif
