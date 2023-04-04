/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:31:05 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 12:05:50 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_write_under_format(char sp, va_list args)
{
	int	res;

	res = -1;
	if (sp == 'c')
		res = ft_write_char((char)va_arg(args, int));
	else if (sp == 's')
		res = ft_write_str(va_arg(args, char *));
	else if (sp == 'p')
		res = ft_write_addr(va_arg(args, void *));
	else if (sp == 'd' || sp == 'i')
		res = ft_write_dec(va_arg(args, int));
	else if (sp == 'u')
		res = ft_write_udec(va_arg(args, unsigned int));
	else if (sp == 'x')
		res = ft_write_shex(va_arg(args, unsigned int));
	else if (sp == 'X')
		res = ft_write_lhex(va_arg(args, unsigned int));
	else if (sp == '%')
		res = write(1, "%", 1);
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	args;
	int		ptr;
	int		tmp;

	va_start(args, s);
	res = 0;
	ptr = -1;
	tmp = 0;
	while (s[++ptr] != '\0')
	{
		if (s[ptr] == '%')
			tmp = ft_write_under_format(s[++ptr], args);
		else
			tmp = write(1, &s[ptr], 1);
		res += tmp;
	}
	va_end(args);
	return (res);
}
