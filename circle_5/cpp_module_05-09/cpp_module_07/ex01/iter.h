/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:56:43 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 21:06:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

template <typename T>
void iter(T* array, unsigned int len, void(*fptr)(T&))
{
	for (unsigned int i = 0; i < len; ++i)
		fptr(array[i]);
}

#endif