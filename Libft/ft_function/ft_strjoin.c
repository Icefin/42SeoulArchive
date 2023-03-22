/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:21:00 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:25:40 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(s1len + s2len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, s1len + 1);
	ft_strlcpy(&ptr[s1len], s2, s2len + 1);
	return (ptr);
}