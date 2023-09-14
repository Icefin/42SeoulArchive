/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:40 by geshin            #+#    #+#             */
/*   Updated: 2023/09/14 15:56:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

#define TRUE	1
#define FALSE	0

static void send_signal(int pid, int signo)
{
	if (signo == SIGUSR1)
		kill(pid, SIGUSR1);
	else if (signo == SIGUSR2)
		kill(pid, SIGUSR2);
	else
		printf("Invalid Signo Input");
	usleep(100);
}

static void process_character_bits(int pid, char utf8)
{
	int bit_pos;

	bit_pos = 8;
	while (--bit_pos >= 0)
	{
		if ((utf8 | (1 << bit_pos)) == TRUE)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
	}
}

static void send(int pid, char *msg)
{
	int	i;

	printf("Send Signal!\n");
	i = -1;
	while (msg[++i] != '\0')
		process_character_bits(pid, msg[i]);
	process_character_bits(pid, '\0');
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
	server_pid = atoi(argv[1]);
	send(server_pid, argv[2]);
	return (0);
}