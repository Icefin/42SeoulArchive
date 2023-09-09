/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:40:51 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 18:08:16 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstp;
	unsigned char	*srcp;

	dstp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	while (n-- > 0)
	{
		*dstp = *srcp;
		dstp++;
		srcp++;
	}	
	return (dst);
}
