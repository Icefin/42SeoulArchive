/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:40 by geshin            #+#    #+#             */
/*   Updated: 2023/09/13 18:03:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
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
}

static void process_character_bits(int pid, int utf8)
{

}

static void send(int pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i] != '\0')
		process_character_bits(pid, msg[i]);
	
}

static int is_valid_arguments(int argc, char **argv)
{
	if (argc != 3)
		return FALSE;
	return TRUE;
}

int main(int argc, char **argv)
{
	if (is_valid_arguments(argc, argv) == FALSE)
		return (1);

	int server_pid = atoi(argv[1]);
	send(server_pid, argv[2]);
	return (0);
}