/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:02 by ajung             #+#    #+#             */
/*   Updated: 2022/03/24 18:29:26 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNAL_H
# define HANDLE_SIGNAL_H

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "input.h"
#include "shell.h"
#include "libft/ftprintf.h"

# define MAIN_PROCESS 0
# define HEREDOC 1
# define CHILD 2
# define PARENT 3

int	handle_signal_parent(void);
int	handle_signal_heredoc(void);
int	handle_signal_child(void);
int	handle_signal_main_process(void);
int	handle_signals(int status);

#endif
