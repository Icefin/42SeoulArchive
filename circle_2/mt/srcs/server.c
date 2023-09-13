/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:38 by geshin            #+#    #+#             */
/*   Updated: 2023/09/13 18:05:23 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

#define TRUE	1
#define FALSE	0

static void flush_buffer(unsigned char *buffer, int size)
{
	
}

static void	receive(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buffer[100];
	static int				i;
	static int				bit_count;

	if (--bit_count == -1)
	{
		bit_count = 7;
		i++;
	}
	buffer[i] &= 0xFF;
	if (signo == SIGUSR1)
		buffer[i] |= (1 << bit_count); 
	else if (signo == SIGUSR2)
		buffer[i] &= ~(1 << bit_count);
	else
		printf("Undefined Signal Accepted\n");
	
	if (buffer[i] == 127 || i == 99)
	{
		write(1, buffer, i + 1);
		if (buffer[i] == 127)
			write(1, "\n", 1);
		flush_buffer(buffer, 100);
		i = 0;
	}
}

int main()
{
	int	pid = getpid();
	printf("Server's PID :  %d\n", pid);

	struct sigaction receiver;

	receiver.__sigaction_u.__sa_sigaction = receive;
	receiver.sa_flags = SA_SIGINFO;

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