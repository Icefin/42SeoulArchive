/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:40 by geshin            #+#    #+#             */
/*   Updated: 2023/09/11 19:02:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

static void send()
{
	
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
	kill(server_pid, SIGUSR1);
	kill(server_pid, SIGUSR2);
	return 0;
}