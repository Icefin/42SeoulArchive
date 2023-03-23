/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:21:11 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:06:03 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*ptr;

	value = (unsigned char)c;
	ptr = (unsigned char *)buffer;
	while (len-- > 0)
	{
		*ptr = value;
		ptr++;
	}
	return (buffer);
}
