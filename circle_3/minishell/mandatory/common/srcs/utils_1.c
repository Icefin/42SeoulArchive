/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:47:15 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:18:31 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != (char)c)
		idx++;
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (0);
}

int	ft_strlen(char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		idx;

	if (ft_strlen(s) <= start)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (ft_strlen(s) - start + 1 <= len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		str[idx] = s[start + idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

void	ft_putstr_fd(char *c, int fd)
{
	int	idx;

	idx = -1;
	while (c[++idx] != '\0')
		write(fd, &c[idx], 1);
}
