/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:11:26 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 15:01:30 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	char		target;

	ptr = s;
	target = (char)c;
	while (*ptr != '\0')
	{
		if (*ptr == target)
			return ((char *)ptr);
		ptr++;
	}
	if (target == '\0')
		return ((char *)ptr);
	return (NULL);
}
