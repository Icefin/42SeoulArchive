/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:32:25 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 19:49:44 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(int n)
{
	int res;

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
	char	*ptr;
	int		digit;
	int		index;

	digit = get_digit(n);
	ptr = (char *)malloc((digit + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[digit] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	index = digit - 1;
	while (n > 0)
	{
		ptr[index] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}