/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:24:42 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 16:53:50 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static char *ft_itohaddr(unsigned long hex)
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

int ft_write_addr(va_list args)
{
    void            *ptr;
    unsigned long   addr;
    char            *hex;

    ptr = va_arg(args, void *);
    if (ptr == 0)
        return (wrtie(1, "(null)", 6));
    addr = (unsigned long)addr;
    hex = ft_itohaddr(addr);
    if (hex == 0)
        return (-1);
    return (write(1, hex, ft_strlen(hex)));
}