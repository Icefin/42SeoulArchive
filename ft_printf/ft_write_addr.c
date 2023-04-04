/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:24:42 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 12:04:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_addr_recursive(const unsigned long p, int depth, int *cnt)
{
	if (p >= 16)
	{
		ft_write_addr_recursive(p / 16, depth + 1, cnt);
		write(1, &"0123456789abcdef"[p % 16], 1);
	}
	else
	{
		write(1, &"0123456789abcdef"[p], 1);
		*cnt += depth;
	}
}

int	ft_write_addr(const void *p)
{
	int				cnt;
	unsigned long	addr;

	addr = (unsigned long)p;
	write(1, "0x", 2);
	cnt = 2;
	ft_write_addr_recursive(addr, 1, &cnt);
	return (cnt);
}
