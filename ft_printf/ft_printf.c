/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:31:05 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 16:41:06 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int  ft_write_under_format(char sp, va_list args)
{
    int res;

    res = -1;
    if (sp == 'c')
        res = ft_write_char(args);
    else if (sp == 's')
        res = ft_write_str(args);
    else if (sp == 'p')
        res = ft_write_addr(args);
    else if (sp == 'd' || sp == 'i')
        res = ft_write_dec(args);
    else if (sp == 'u')
        res = ft_write_udec(args);
    else if (sp == 'x')
        res = ft_write_shex(args);
    else if (sp == 'X')
        res = ft_write_bhex(args);
    else if (sp == '%')
        res = write(1, '%', 1);
    return (res);
}

int ft_printf(const char *s, ...)
{
    int     res;
    va_list args;
    int     ptr;
    int     tmp;

    va_start(args, s);
    res = 0;
    ptr = -1;
    tmp = 0;
    while (s[++ptr] != '\0')
    {
        if (s[ptr] == '%')
            tmp = ft_write_under_format(s[++ptr], args);
        else
            tmp = write(1, s[ptr], 1);
        if (tmp == -1)
        {
            va_end(args);
            return (-1);
        }
        res += tmp;
    }
    va_end(args);
    return (res);
}