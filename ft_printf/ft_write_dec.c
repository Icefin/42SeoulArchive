/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:25:23 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 16:48:13 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static char    *ft_itoa(int value)
{
    //Implement this
}

static int  ft_strlen(char *s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

int ft_write_dec(va_list args)
{
    int     value;
    char    *str;

    value = va_arg(args, int);
    str = ft_itoa(value);
    if (str == 0)
        return (-1);
    return (write(1, str, ft_strlen(str)));
}

int ft_write_udec(va_list args)
{
    unsigned int    value;
    char            *str;

    value = va_arg(args, unsigned int);
    str = ft_itoa(value);
    if (str == 0)
        return (-1);
    return (write(1, str, ft_strlen(str)));
}