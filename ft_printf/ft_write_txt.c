/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:28:20 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 16:08:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int  ft_strlen(char *s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

int ft_write_char(va_list args)
{
    char    c;

    c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

int ft_write_str(va_list args)
{
    char    *str;

    str = va_arg(args, char *);
    if (str == 0)
        return (write(1, "(null)", 6));
    return (write(1, str, ft_strlen(str)));
}