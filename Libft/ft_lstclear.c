/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:33:06 by geshin            #+#    #+#             */
/*   Updated: 2023/03/24 14:32:56 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO : Implement this function
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst != NULL)
	{
		node = *lst;
		(*lst) = (*lst)->next;
		ft_lstdelone(node, del);
	}
}
