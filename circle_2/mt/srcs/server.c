/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:38 by geshin            #+#    #+#             */
/*   Updated: 2023/09/13 17:55:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

#define TRUE	1
#define FALSE	0

static void	receive(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
	{

	}
	else if (signo == SIGUSR2)
	{

	}
	else
		printf("Undefined Signal Accepted\n");
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