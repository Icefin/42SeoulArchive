/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:23:22 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/11 17:16:59 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

void	destroy_2d_array(char **arr)
{
	int n;
	int	i;

	n = ft_arrlen(arr);
	i = -1;
	while (++i <= n)
		free(arr[i]);
	free(arr);
}

long long	ft_stoi_plus_imax(char *s)
{
	long long	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		res = res * 10 + (s[i] - '0');
		if ((sign * res) > 2147483647)
			return (-1);
		if ((sign * res) < -2147483648)
			return (-1);
		i++;
	}
	return ((sign * res) + 2147483648);
}