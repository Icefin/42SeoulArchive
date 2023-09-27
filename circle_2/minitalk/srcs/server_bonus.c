/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:30:57 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/27 17:53:32 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

#define FALSE	0
#define TRUE	1

static void	receive_character_per_bit(int signo, char *c, int bit)
{
	if (signo == SIGUSR1)
		*c &= ~(1 << bit);
	else if (signo == SIGUSR2)
		*c |= (1 << bit);
}

static void	receive(int signo, siginfo_t *info, void *context)
{
	static int		bit = 7;
	static char		c;

	(void)context;
	receive_character_per_bit(signo, &c, bit);
	if (--bit < 0)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bit = 7;
	}
}

int	main(void)
{
	struct sigaction	receiver;
	pid_t				server_pid;

	receiver.__sigaction_u.__sa_sigaction = receive;
	receiver.sa_flags = SA_SIGINFO;
	sigemptyset(&receiver.sa_mask);
	server_pid = getpid();
	ft_printf("Server's PID :  %d\n", server_pid);
	if (sigaction(SIGUSR1, &receiver, NULL) == -1)
	{
		write(1, "Unable to use SIGUSR1\n", 22);
		return (1);
	}
	if (sigaction(SIGUSR2, &receiver, NULL) == -1)
	{
		write(1, "Unable to use SIGUSR2\n", 22);
		return (1);
	}
	while (TRUE)
		pause();
	return (0);
}
