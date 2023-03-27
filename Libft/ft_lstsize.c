/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:58:33 by geshin            #+#    #+#             */
/*   Updated: 2023/03/27 14:45:27 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*node;

	if (lst == NULL)
		return (0);
	cnt = 1;
	node = lst;
	while (node->next != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
