/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:34 by geshin            #+#    #+#             */
/*   Updated: 2023/04/04 12:57:21 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content, int size)
{
	t_list	*node;
	char	*text;

	node = (t_list *)malloc(sizeof(t_list));
	text = ft_strdup(content, size);
	if (node == NULL || text == NULL)
		return (NULL);
	node->text = text;
	node->text_len = size;
	node->next = NULL;
	return (node);
}

void	ft_lst_node_add_back(t_list **lst, t_list *new)
{
	t_list	*node;

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

void	ft_lstclear(t_list **lst)
{
	t_list	*node;

	while (*lst != NULL)
	{
		node = *lst;
		(*lst) = (*lst)->next;
		free(node->text);
		free(node);
	}
}

char	*ft_strdup(const char *src, int srclen)
{
	char	*res;

	res = (char *)malloc((srclen) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strmove(res, src, srclen);
	return (res);
}

void	ft_strmove(char *dst, const char *src, int srclen)
{
	int	idx;

	idx = 0;
	while (idx < srclen)
	{
		dst[idx] = src[idx];
		idx++;
	}
}
