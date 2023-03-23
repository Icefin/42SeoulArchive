/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:22 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 19:39:14 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_isspace(const char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	idx;
	int	sign;
	int	res;

	idx = 0;
	sign = 1;
	res = 0;
	while ((my_isspace(s[idx])))
		idx++;
	if (s[idx] == '+' || s[idx] == '-')
	{
		if (s[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_isdigit(s[idx]))
	{
		res = res * 10 + (s[idx] - '0');
		idx++;
	}
	return (sign * res);
}
