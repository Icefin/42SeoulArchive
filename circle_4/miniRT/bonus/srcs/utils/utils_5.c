/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:58:29 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/20 15:25:54 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	ft_check_prefix(const char *str, int *sign)
{
	int	idx;

	idx = 0;
	while (ft_isspace(str[idx]))
		idx++;
	*sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			*sign = -1;
		idx++;
	}
	return (idx);
}

double	ft_atod(const char *str)
{
	double	num;
	double	dec;
	int		sign;
	int		idx;

	idx = ft_check_prefix(str, &sign);
	num = 0;
	while (ft_isdigit(str[idx]))
	{
		num = (num * 10) + (str[idx] - '0') * sign;
		idx++;
	}
	dec = 10;
	if (str[idx++] == '.')
	{
		while (ft_isdigit(str[idx]))
		{
			num = num + ((str[idx] - '0') / dec) * sign;
			dec *= 10;
			idx++;
		}
	}
	return (num);
}
