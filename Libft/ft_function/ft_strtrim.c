/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:35 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 19:02:25 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hash_set(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		left;
	int		right;
	char	*ptr;

	left = 0;
	right = ft_strlen(s1) - 1;
	while (s1[left] != '\0')
	{
		if (hash_set(set, s1[left]) == 0)
			break;
		left++;
	}
	while (right >= 0)
	{
		if (hash_set(set, s1[right]) == 0)
			break;
		right--;
	}
	if (left > right)
		return (NULL);
	ptr = (char *)malloc((right - left + 2) * sizeof(char));
	ft_strlcpy(ptr, &s1[left], right - left + 2);
	return (ptr);
}