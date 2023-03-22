/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:20:22 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:04:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	target;
	size_t			i;

	ptr = s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == target)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
