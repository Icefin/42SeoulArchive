/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:25 by geshin            #+#    #+#             */
/*   Updated: 2023/04/12 12:54:09 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static int	get_endl_idx(const char *buffer, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (buffer[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

static int	buffer_text_process(t_list **lst, char *buffer, int *bsl, int size)
{
	t_list	*node;
	int		endl_idx;

	endl_idx = get_endl_idx(buffer, size);
	if (endl_idx == -1)
	{
		node = ft_lstnew(buffer, size);
		ft_lst_node_add_back(lst, node);
		*bsl = 0;
		return (1);
	}
	node = ft_lstnew(buffer, endl_idx + 1);
	ft_lst_node_add_back(lst, node);
	ft_strmove(buffer, &buffer[endl_idx + 1], size - endl_idx);
	*bsl = size - endl_idx;
	return (0);
}

static char	*get_entire_line(t_list **lst)
{
	char	*res;
	int		len;
	t_list	*node;
	int		idx;

	len = 0;
	node = *lst;
	while (node != NULL)
	{
		len += node->text_len;
		node = node->next;
	}
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	node = *lst;
	idx = 0;
	while (node != NULL)
	{
		ft_strmove(&res[idx], node->text, node->text_len);
		idx += node->text_len;
		node = node->next;
	}
	res[idx] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_text_len;
	char		*line;
	t_list		*head;
	int			rd_size;
	
	head = ft_lstnew(buffer, buffer_text_len);
	rd_size = read(fd, buffer, BUFFER_SIZE);
	while (rd_size > 0)
	{
		rd_size = buffer_text_process(&head, buffer, &buffer_text_len, rd_size);
		if (rd_size == 0)
			break ;
		rd_size = read(fd, buffer, BUFFER_SIZE);
	}
	if (rd_size < 0)
	{
		ft_lstclear(&head);
		return (NULL);
	}
	line = get_entire_line(&head);
	ft_lstclear(&head);
	return (line);
}

//content로 NULL이 들어가는 경우 처리해야댐
//endl받고 끝내는 것도 해야댐