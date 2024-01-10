/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:57:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:59:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain
{
public :
	Brain();
	Brain(const Brain& rhs);
	~Brain();

	Brain& operator=(const Brain& rhs);

private :
	std::string ideas[100];	
};

#endif