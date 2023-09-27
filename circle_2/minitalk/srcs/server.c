/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:32 by geshin            #+#    #+#             */
/*   Updated: 2023/09/27 17:53:31 by singeonho        ###   ########.fr       */
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
	static int	bit = 7;
	static char	c;

	(void)info;
	(void)context;
	receive_character_per_bit(signo, &c, bit);
	if (--bit < 0)
	{
		write(1, &c, 1);
		c = 0;
		bit = 7;
	}
}

int	main(void)
{
	struct sigaction	receiver;
	int					pid;

	receiver.__sigaction_u.__sa_sigaction = receive;
	receiver.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("Server's PID :  %d\n", pid);
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
		;
	return (0);
}
