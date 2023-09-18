/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:32 by geshin            #+#    #+#             */
/*   Updated: 2023/09/18 13:50:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

#define FALSE			0
#define TRUE			1
#define MAX_BUFFER_SIZE 100

/*
static void	flush_buffer(unsigned char *buffer, int size)
{
	for (int i = 0; i < 100; ++i)
		buffer[i] = 0x7F;
}
*/

/*
static void receive_character_per_bit(int signo)
{
	int		bit;
	char	character;

	bit = 8;
	while (--bit >= 0)
	{
		if (signo == FALSE)
		{

		}
		else

	}
}
*/

static void	receive(int signo, siginfo_t *info, void *context)
{
	static char	buffer[MAX_BUFFER_SIZE];
	static int	bit;
	static int	i;

	(void)info;
	(void)context;
	if (--bit < 0)
	{
		bit = 7;
		i++;
		if (i == MAX_BUFFER_SIZE)
		{
			write(1, &buffer[1], MAX_BUFFER_SIZE);
			i = 1;
		}
		buffer[i] = 0x7F;
	}

	if (signo == SIGUSR1)
		buffer[i] &= ~(1 << bit);
	else if (signo == SIGUSR2)
		buffer[i] |= (1 << bit);

	if (buffer[i] == '\0' || i == MAX_BUFFER_SIZE)
	{
		write(1, &buffer[1], i);
		if (buffer[i] == '\0')
			write(1, "\n", 1);
		bit = 0;
		i = 0;
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
		write(1, "Unable to use SIGUSR2\n", 22);
		return (1);
	}
	if (sigaction(SIGUSR2, &receiver, NULL) == -1)
	{
		write(1, "Unable to use SIGUSR2\n", 22);
		return (1);
	}
	while (TRUE) ;
	return (0);
}