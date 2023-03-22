/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:15:11 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:08:17 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = s;
	i = (int)ft_strlen(s);
	if (c == '\0')
		return (&ptr[i]);
	i--;
	while (i >= 0)
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}
