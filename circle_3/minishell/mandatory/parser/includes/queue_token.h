/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:42:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 17:22:55 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_TOKEN_H
# define QUEUE_TOKEN_H

# include "token.h"

typedef struct s_queue_token
{
	t_token	**data;
	int		size;
	int		capacity;
}	t_queue_token;

t_queue_token	*queue_token_constructor(int size);
void			queue_token_destructor(t_queue_token *q);

void			queue_token_push(t_queue_token *q, t_token t);
void			queue_token_pop(t_queue_token *q);

t_token			*queue_token_get_front(t_queue_token *q);
int				queue_token_is_empty(t_queue_token *q);

#endif