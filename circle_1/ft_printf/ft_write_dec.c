/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:25:23 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 12:08:27 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_udec_recursive(unsigned int n, int depth, int *cnt)
{
	char	c;

	if (n >= 10)
	{
		ft_write_udec_recursive(n / 10, depth + 1, cnt);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		*cnt += depth;
	}
}

int	ft_write_dec(const int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		cnt++;
		ft_write_udec_recursive((unsigned int)(-n), 1, &cnt);
	}
	else
		ft_write_udec_recursive(n, 1, &cnt);
	return (cnt);
}

int	ft_write_udec(const unsigned int n)
{
	int	cnt;

	cnt = 0;
	ft_write_udec_recursive(n, 1, &cnt);
	return (cnt);
}
