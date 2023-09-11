/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:16:16 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 18:08:18 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstp;
	unsigned char	*srcp;

	dstp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	if (dstp < srcp)
	{
		while (len-- > 0)
		{
			*dstp = *srcp;
			dstp++;
			srcp++;
		}
	}
	else
	{
		while (len-- > 0)
			dstp[len] = srcp[len];
	}
	return (dst);
}
