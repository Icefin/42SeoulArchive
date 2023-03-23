/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:32:25 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 18:00:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(long long n)
{
	int	res;

	if (n == INT32_MIN)
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

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	tmp;
	int			digit;
	int			index;

	tmp = (long long)n;
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
	index = digit - 1;
	while (tmp > 0)
	{
		ptr[index--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (ptr);
}
