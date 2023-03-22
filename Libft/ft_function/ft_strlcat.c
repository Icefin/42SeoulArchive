/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:02:42 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:06:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	res;
	size_t	i;

	dstlen = ft_strlen(dst);
	res = dstlen + ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (res);
}
