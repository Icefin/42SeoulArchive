/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:30:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/26 19:21:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

#define FALSE	0
#define TRUE	1

static void	send_character_per_bit(int pid, char utf8)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if ((utf8 & (1 << bit)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	send(int pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i] != '\0')
		send_character_per_bit(pid, msg[i]);
	send_character_per_bit(pid, '\n');
	send_character_per_bit(pid, '\0');
}

static void	confirm(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Feedback from Server!\n");
	exit(0);
}

static int	is_valid_arguments(int argc, char **argv)
{
	if (argc != 3 || argv[2] == 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (is_valid_arguments(argc, argv) == FALSE)
		return (1);
	signal(SIGUSR1, confirm);
	server_pid = ft_atoi(argv[1]);
	send(server_pid, argv[2]);
	while (TRUE)
		pause();
	return (0);
}
