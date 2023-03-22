/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:16:16 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:23:28 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len + 1);
	return (ptr);
}