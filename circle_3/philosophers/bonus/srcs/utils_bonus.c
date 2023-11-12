/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:56:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/12 15:58:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "commontype_bonus.h"
#include "utils_bonus.h"

static t_bool	is_space(const char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(char *s)
{
	int	res;
	int	idx;
	int	sign;

	res = 0;
	idx = 0;
	sign = 1;
	while (is_space(s[idx]) == TRUE)
		idx++;
	if (s[idx] == '+' || s[idx] == '-')
	{
		if (s[idx] == '-')
			sign = -1;
		idx++;
	}
	while (is_digit(s[idx]))
	{
		res = res * 10 + (s[idx] - '0');
		idx++;
	}
	return (sign * res);
}

t_int64	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}