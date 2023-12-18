/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:56:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:38:49 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils_bonus.h"

static int	get_digit(long long n)
{
	int	res;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
		return (get_digit(-n) + 1);
	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int num)
{
	char		*ptr;
	long long	tmp;
	int			digit;
	int			idx;

	tmp = (long long)num;
	digit = get_digit(tmp);
	ptr = (char *)malloc((digit + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[digit] = '\0';
	if (tmp == 0)
		ptr[0] = '0';
	if (tmp < 0)
	{
		ptr[0] = '-';
		tmp = -tmp;
	}
	idx = digit - 1;
	while (tmp > 0)
	{
		ptr[idx--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (ptr);
}

static t_bool	is_space(const char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
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
	while (s[idx] >= '0' && s[idx] <= '9')
	{
		res = res * 10 + (s[idx] - '0');
		idx++;
	}
	return (sign * res);
}
