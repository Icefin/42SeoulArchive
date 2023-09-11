/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:32:36 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 11:59:30 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_write_char(const char c);
int	ft_write_str(const char *s);
int	ft_write_addr(const void *p);
int	ft_write_dec(const int n);
int	ft_write_udec(const unsigned int n);
int	ft_write_shex(const unsigned int n);
int	ft_write_lhex(const unsigned int n);

int	ft_printf(const char *s, ...);

#endif
