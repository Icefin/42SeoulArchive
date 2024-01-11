/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:03:20 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/11 11:48:00 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include <pthread.h>
# include "minirt.h"

# define THREAD_CNT 8

typedef struct s_child
{
	pthread_t		thread;
	int				miny;
	int 			maxy;
	t_image			*image;
	t_minirt		*minirt;
	t_camera		*camera;
}	t_child;

#endif