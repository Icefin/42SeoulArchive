/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:41 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 12:04:46 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_shex_recursive(const unsigned int n, int depth, int *cnt)
{
	if (n >= 16)
	{
		ft_write_shex_recursive(n / 16, depth + 1, cnt);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
	{
		write(1, &"0123456789abcdef"[n], 1);
		*cnt += depth;
	}
}

static void	ft_write_lhex_recursive(const unsigned int n, int depth, int *cnt)
{
	if (n >= 16)
	{
		ft_write_lhex_recursive(n / 16, depth + 1, cnt);
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[n], 1);
		*cnt += depth;
	}
}

int	ft_write_shex(const unsigned int n)
{
	int	cnt;

	cnt = 0;
	ft_write_shex_recursive(n, 1, &cnt);
	return (cnt);
}

int	ft_write_lhex(const unsigned int n)
{
	int	cnt;

	cnt = 0;
	ft_write_lhex_recursive(n, 1, &cnt);
	return (cnt);
}
