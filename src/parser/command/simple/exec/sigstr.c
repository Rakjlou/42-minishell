/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:52:17 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/09 23:00:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "libft.h"

static void	sigstr_init_1(char *message[NSIG])
{
	ft_bzero(message, NSIG * sizeof(char));
	message[SIGHUP] = "Hangup";
	message[SIGINT] = "Interrupt";
	message[SIGQUIT] = "Quit";
	message[SIGILL] = "Illegal instruction";
	message[SIGTRAP] = "BPT trace/trap";
	message[SIGABRT] = "Aborted";
	message[SIGFPE] = "Floating point exception";
	message[SIGKILL] = "Killed";
	message[SIGBUS] = "Bus error";
	message[SIGSEGV] = "Segmentation fault";
	message[SIGSYS] = "Bad system call";
	message[SIGPIPE] = "Broken pipe";
	message[SIGALRM] = "Alarm clock";
	message[SIGTERM] = "Terminated";
	message[SIGURG] = "Urgent IO condition";
	message[SIGSTOP] = "Stopped (signal)";
	message[SIGTSTP] = "Stopped";
	message[SIGCONT] = "Continue";
	message[SIGCHLD] = "Child death or stop";
	message[SIGTTIN] = "Stopped (tty input)";
	message[SIGTTOU] = "Stopped (tty output)";
	message[SIGIO] = "I/O ready";
	message[SIGXCPU] = "CPU limit";
	message[SIGXFSZ] = "File limit";
}

static void	sigstr_init_2(char *message[NSIG])
{
	message[SIGVTALRM] = "Alarm (virtual)";
	message[SIGPROF] = "Alarm (profile)";
	message[SIGWINCH] = "Window changed";
	message[SIGUSR1] = "User signal 1";
	message[SIGUSR2] = "User signal 2";
	message[SIGPWR] = "power failure imminent";
}

char	*sigstr(int sig)
{
	char	*message[NSIG];

	sigstr_init_1(message);
	sigstr_init_2(message);
	if (sig < 0 || sig >= NSIG)
		return (NULL);
	return (message[sig]);
}
