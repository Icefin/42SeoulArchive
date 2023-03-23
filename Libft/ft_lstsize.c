/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:58:33 by geshin            #+#    #+#             */
/*   Updated: 2023/03/23 13:44:35 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		cnt;

	if (lst == NULL)
		return (0);
	node = lst;
	cnt = 1;
	while (node->next != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
