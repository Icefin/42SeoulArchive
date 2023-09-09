/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:24 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 18:50:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

void	post(int pid, int idx)
{
	if (idx == 1)
		kill(pid, SIGUSR1);
	else if (idx == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	conv_and_post(int pid, int c, int num)
{
	if (!c)
	{
		while (num < 8)
		{
			post(pid, 0);
			num++;
		}
		return ;
	}
	else
	{
		conv_and_post(pid, c / 2, ++num);
		post(pid, c % 2);
	}
}

void	post_office(int pid, char *str)
{
	int		c;
	int		num;
	int		idx;
	int		last;

	c = 0;
	idx = -1;
	last = 7;
	while (str[++idx])
	{
		num = 0;
		c = (int)str[idx];
		conv_and_post(pid, c, num);
	}
	post(pid, 0);
	while (last--)
		post(pid, 1);
}

int		main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
	{
		write(1, "Client PID : ", 13);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\nMassage : ", 11);
		write(1, argv[2], ft_strlen(argv[2]));
		write(1, "\n", 1);
		post_office(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}