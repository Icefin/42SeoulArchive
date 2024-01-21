/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:44:06 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 22:46:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

template<typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator iter = container.begin();
	while (iter != container.end())
	{
		if (*iter == target)
			return iter;
		++iter;
	}
	return container.end();
}

#endif