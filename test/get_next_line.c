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

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static char	*get_line_from_list(t_list **head)
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
		lst_pop_front(head);
	}
	return (res);
}

void	split_buffer_endl(t_list **head, t_list **tail, char *s, int slen)
{
	char	*text;
	int		left;
	int		right;
	t_list	*tmp;

	left = 0;
	right = 0;
	while (right < slen)
	{
		if (s[right] == '\n')
		{
			text = str_substr(s, left, right - left + 1);
			tmp = lst_create_node(text, right - left + 1, 1);
			lst_push_back(head, tail, tmp);
			left = right + 1;
		}
		right++;
	}
	if (right > left)
	{
		text = str_substr(s, left, right - left);
		tmp = lst_create_node(text, right - left, 0);
		lst_push_back(head, tail, tmp);
	}
}

static void	update_linked_list(t_list **head, t_list **tail, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		rd_size;

	rd_size = read(fd, buffer, BUFFER_SIZE);
	while (rd_size > 0)
	{
		split_buffer_endl(head, tail, buffer, rd_size);
		rd_size = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	static t_list	*tail;
	char			*res;

	update_linked_list(&head, &tail, fd);
	if (head == NULL)
	{
		tail = NULL;
		return (NULL);
	}
	res = get_line_from_list(&head);
	if (head == NULL)
		tail = NULL;
	return (res);
}
