/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:15:11 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 19:42:20 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	const char	*ptr;
	int			idx;

	target = (char)c;
	ptr = s;
	idx = (int)ft_strlen(s);
	if (target == '\0')
		return ((char *)&ptr[idx]);
	idx--;
	while (idx >= 0)
	{
		if (ptr[idx] == target)
			return ((char *)&ptr[idx]);
		idx--;
	}
	return (NULL);
}
