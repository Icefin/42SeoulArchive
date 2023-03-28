/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:34 by geshin            #+#    #+#             */
/*   Updated: 2023/03/28 17:37:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*ft_get_line_lst(fd)
{
	t_node	*node;
	char	*buffer;
	int		rd_size;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	rd_size = read(fd, buffer, BUFFER_SIZE);
	while (rd_size > 0)
	{
		node = (t_node *)malloc(sizeof(t_node));
		
	}
}

int	ft_get_node_cnt(t_node* head)
{
	int		cnt;
	t_list	*node;

	if (head == NULL)
		return (0);
	cnt = 1;
	node = head;
	while (node->next != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*node;

	node = *lst;
	if (node == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = new;
}

void	ft_lstclear(t_node **lst)
{
	t_node	*node;

	while (*lst != NULL)
	{
		node = *lst;
		(*lst) = (*lst)->next;
		free(node->content);
		free(node);
	}
}