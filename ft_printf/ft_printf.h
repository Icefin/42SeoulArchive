/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:32:36 by geshin            #+#    #+#             */
/*   Updated: 2023/03/31 14:12:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int ft_write_char();
int ft_write_str();
int ft_write_addr();
int ft_write_dec();
int ft_write_udec();
int ft_write_shex();
int ft_write_bhex();

int ft_printf(const char *s, ...);

#endif