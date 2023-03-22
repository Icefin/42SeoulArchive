/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:26:08 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:08:10 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndlen;
	size_t	i;

	ndlen = ft_strlen(needle);
	i = 0;
	while (haystack[i] != '\0' && i + ndlen < len)
	{
		if (ft_strncmp(&haystack[i], needle, ndlen))
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
