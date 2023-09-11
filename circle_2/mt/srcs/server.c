/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:38 by geshin            #+#    #+#             */
/*   Updated: 2023/09/11 19:04:41 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

#define TRUE	1
#define FALSE	0

void	receive(int signo, siginfo_t *info, void *context)
{
	printf("Receive Some Signal! : %d\n", signo);
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