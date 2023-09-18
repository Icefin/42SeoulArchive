/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:40 by geshin            #+#    #+#             */
/*   Updated: 2023/09/18 20:43:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define FALSE	0
#define TRUE	1

static void send_signal(int pid, int signo)
{
	if (signo == SIGUSR1)
		kill(pid, SIGUSR1);
	else if (signo == SIGUSR2)
		kill(pid, SIGUSR2);
	else
	{
		write(1, "Invalid Signo Input\n", 20);
		exit(1);
	}
		
	usleep(100);
}

static void send_character_per_bit(int pid, char utf8)
{
	int bit;

	bit = 8;
	while (--bit >= 0)
	{
		if ((utf8 & (1 << bit)) == FALSE)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
	}
}

static void send(int pid, char *msg)
{
	int	i;

	write(1, "Send Signal!\n", 13);
	i = -1;
	while (msg[++i] != '\0')
		send_character_per_bit(pid, msg[i]);
	send_character_per_bit(pid, '\0');
}

static int is_valid_arguments(int argc, char **argv)
{
	if (argc != 3 || argv[2] == 0)
		return FALSE;
	return TRUE;
}

int main(int argc, char **argv)
{
	int	server_pid;

	if (is_valid_arguments(argc, argv) == FALSE)
		return (1);
	server_pid = ft_atoi(argv[1]);
	send(server_pid, argv[2]);
	return (0);
}