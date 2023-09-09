/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:32 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 18:53:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	*reset(void *b, size_t len)
{
	unsigned char	*temp;
	unsigned long	i;

	temp = (unsigned char*)b;
	i = -1;
	while (++i < len)
		temp[i] &= 0;
	return (temp);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buf[100];
	static int				idx;
	static int				count;

	(void)info;
	(void)context;
	if (--count == -1)
	{
		count = 7;
		idx++;
	}
	buf[idx] &= ~128;
	if (signo == SIGUSR1)
		buf[idx] |= (1 << count);
	else if (signo == SIGUSR2)
		buf[idx] &= ~(1 << count);
	if (buf[idx] == 127 || idx == 99)
	{
		write(1, buf, idx + 1);
		if (buf[idx] == 127)
			write(1, "\n", 1);
		reset(buf, 100);
		idx = 0;
	}
}

int		display_pid()
{
	char *pid;

	if (!(pid = ft_itoa(getpid())))
		return (0);
	write(1, "My PID is ", 10);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	return (1);
}

int		main(void)
{
	struct sigaction	act1;

	act1.sa_sigaction = handler;
	act1.sa_flags = SA_SIGINFO;
	if (!(display_pid()))
	{
		write(1, "PID malloc error", 16);
		exit(1);
	}
	if (sigaction(SIGUSR1, &act1, NULL) != 0)
	{
		write(1, "Sigaction Error", 15);
		exit(1);
	}
	if (sigaction(SIGUSR2, &act1, NULL) != 0)
	{
		write(1, "Sigaction Error", 15);
		exit(1);
	}
	while (1)
		;
	return (0);
}