/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:32 by geshin            #+#    #+#             */
/*   Updated: 2023/09/16 10:47:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

#define FALSE	0
#define TRUE	1

static void	flush_buffer(unsigned char *buffer, int size)
{
	for (int i = 0; i < 100; ++i)
		buffer[i] = 0x7F;
}

static void	receive(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buffer[100];
	static int				i;
	static int				bit_pos ;

	(void)info;
	(void)context;
	if (--bit_pos < 0)
	{
		bit_pos = 7;
		i++;
		buffer[i] = 0x7F;
	}
	if (signo == SIGUSR1)
		buffer[i] &= ~(1 << bit_pos);
	else if (signo == SIGUSR2)
		buffer[i] |= (1 << bit_pos); 
	if (buffer[i] == 0 || i == 99)
	{
		write(1, buffer, i + 1);
		if (buffer[i] == 0)
			write(1, "\n", 1);
		i = 0;
		bit_pos = 0;
		flush_buffer(buffer, 100);
	}
}

int main()
{
	struct sigaction	receiver;
	int					pid;

	receiver.__sigaction_u.__sa_sigaction = receive;
	receiver.sa_flags = SA_SIGINFO;

	pid = getpid();
	printf("Server's PID :  %d\n", pid);
	if (sigaction(SIGUSR1, &receiver, NULL) == -1)
	{
		write(1, "Unable to use SIGUSR1", 21);
		return (1);
	}
	if (sigaction(SIGUSR2, &receiver, NULL) == -1)
	{
		write(1, "Unable to use SIGUSR2", 21);
		return (1);
	}
	while (TRUE) ;
	return (0);
}