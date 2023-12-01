/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:52:47 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/01 16:51:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

void	ft_sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	//rl_replace_line("", 0);
	rl_redisplay();
}

void	init_signal(void)
{
	//rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint_handler);
}

void	ft_signal_heredoc(int signum)
{
	(void)signum;
	printf("\n");
	exit(1);
}
