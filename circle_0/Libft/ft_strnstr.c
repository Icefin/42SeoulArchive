/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:26:08 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 19:47:01 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndlen;
	size_t	idx;

	ndlen = ft_strlen(needle);
	if (ndlen == 0)
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] != '\0' && idx + ndlen <= len)
	{
		if (ft_strncmp(&haystack[idx], needle, ndlen) == 0)
			return ((char *)&haystack[idx]);
		idx++;
	}
	return (NULL);
}
