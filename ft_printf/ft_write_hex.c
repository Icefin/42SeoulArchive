/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:41 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 16:51:05 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

//Consider Upper case, Lower case

static char *ft_itoh(int value)
{
    //Implment this
}

static int  ft_strlen(char *s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

int ft_write_shex(va_list args)
{
    int     value;
    char    *hex;
    
    value = va_arg(args, int);
    hex = ft_itoh(value);
    if (hex == 0)
        return (-1);
    return (write(1, hex, ft_strlen(hex)));
}

int ft_write_bhex(va_list args)
{
    int     value;
    char    *hex;

    value = va_arg(args, int);
    hex = ft_itoh(value);
    if (hex == 0)
        return (-1);
    return (write(1, hex, ft_strlen(hex)));
}