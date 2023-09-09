/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:20:22 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 19:39:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	target;
	size_t			idx;

	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	idx = 0;
	while (idx < n)
	{
		if (ptr[idx] == target)
			return (&ptr[idx]);
		idx++;
	}
	return (NULL);
}
