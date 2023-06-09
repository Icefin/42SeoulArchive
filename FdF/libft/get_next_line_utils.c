/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:08:52 by geshin            #+#    #+#             */
/*   Updated: 2023/06/09 16:08:09 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_substr(char *s, int sidx, int len)
{
	char	*res;
	int		idx;

	res = (char *)malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res[idx] = s[sidx + idx];
		idx++;
	}
	return (res);
}

void	str_strncat(char *s, int len, t_list *node)
{
	int	idx;

	idx = -1;
	while (++idx < node->text_len)
		s[len + idx] = node->text[idx];
	s[len + idx] = '\0';
}

t_list	*lst_create_node(char *text, int len, int is_eol)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->text = text;
	res->is_eol = is_eol;
	res->text_len = len;
	res->next = NULL;
	return (res);
}

void	lst_push_back(t_list **head, t_list **tail, t_list *node)
{
	if (*head == NULL)
	{
		*head = node;
		*tail = node;
		return ;
	}
	(*tail)->next = node;
	*tail = node;
}

void	lst_pop_front(t_list **head, t_list **tail)
{
	t_list	*tmp;

	if (*head == NULL)
	{
		*tail = NULL;
		return ;
	}
	tmp = *head;
	*head = (*head)->next;
	if (*head == NULL)
		*tail = NULL;
	tmp->next = NULL;
	free(tmp->text);
	free(tmp);
}
