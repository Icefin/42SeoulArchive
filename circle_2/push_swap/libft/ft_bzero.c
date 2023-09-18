/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:38:13 by geshin            #+#    #+#             */
/*   Updated: 2023/03/22 18:02:35 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buffer, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buffer;
	while (n-- > 0)
	{
		*ptr = 0;
		ptr++;
	}
}
