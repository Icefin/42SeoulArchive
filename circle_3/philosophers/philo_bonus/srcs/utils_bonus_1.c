/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:56:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/16 15:31:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "commontype_bonus.h"
#include "utils_bonus.h"

static t_bool	is_space(const char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (TRUE);
	return (FALSE);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	if (dstsize == 0)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] != '\0' && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
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

static int	get_digit(long long n)
{
	int	res;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
		return (get_digit(-n) + 1);
	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int num)
{
	char		*ptr;
	long long	tmp;
	int			digit;
	int			idx;

	tmp = (long long)num;
	digit = get_digit(tmp);
	ptr = (char *)malloc((digit + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[digit] = '\0';
	if (tmp == 0)
		ptr[0] = '0';
	if (tmp < 0)
	{
		ptr[0] = '-';
		tmp = -tmp;
	}
	idx = digit - 1;
	while (tmp > 0)
	{
		ptr[idx--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (ptr);
}

int	ft_atoi(char *s)
{
	int	res;
	int	idx;
	int	sign;

	res = 0;
	idx = 0;
	sign = 1;
	while (is_space(s[idx]) == TRUE)
		idx++;
	if (s[idx] == '+' || s[idx] == '-')
	{
		if (s[idx] == '-')
			sign = -1;
		idx++;
	}
	while (s[idx] >= '0' && s[idx] <= '9')
	{
		res = res * 10 + (s[idx] - '0');
		idx++;
	}
	return (sign * res);
}

t_int64	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
