/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:08:46 by geshin            #+#    #+#             */
/*   Updated: 2023/04/12 16:28:39 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static char	*get_line_from_list(t_list **head, t_list **tail)
{
	char	*res;
	t_list	*tmp;
	int		len;
	int		is_eol;

	len = 0;
	is_eol = 0;
	tmp = *head;
	while (tmp != NULL && !is_eol)
	{
		len += tmp->text_len;
		is_eol = tmp->is_eol;
		tmp = tmp->next;
	}
	res = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	is_eol = 0;
	while ((*head) != NULL && !is_eol)
	{
		is_eol = (*head)->is_eol;
		str_strncat(res, len, (*head));
		len += (*head)->text_len;
		lst_pop_front(head, tail);
	}
	return (res);
}

static int	split_buffer_endl(t_list **head, t_list **tail, char *s, int slen)
{
	char	*text;
	int		left;
	int		right;
	t_list	*tmp;
	int		is_eol;

	left = 0;
	right = -1;
	is_eol = 0;
	while (++right < slen)
	{
		if (s[right] == '\n' || right == slen - 1)
		{
			if (s[right] == '\n')
				is_eol = 1;
			text = str_substr(s, left, right - left + 1);
			if (s[right] == '\n')
				tmp = lst_create_node(text, right - left + 1, 1);
			else
				tmp = lst_create_node(text, right - left + 1, 0);
			lst_push_back(head, tail, tmp);
			left = right + 1;
		}
	}
	return (is_eol);
}

static void	update_linked_list(t_list **head, t_list **tail, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		rd_size;
	int		is_eol;

	is_eol = 0;
	while (!is_eol)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		is_eol = split_buffer_endl(head, tail, buffer, rd_size);
	}
	if (rd_size < 0)
	{
		while (*head != NULL)
			lst_pop_front(head, tail);
		*head = NULL;
		*tail = NULL;
	}
}

static int	is_prev_eol(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->is_eol)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	static t_list	*tail;

	if (is_prev_eol(&head))
		return (get_line_from_list(&head, &tail));
	update_linked_list(&head, &tail, fd);
	if (head == NULL)
		return (NULL);
	return (get_line_from_list(&head, &tail));
}
