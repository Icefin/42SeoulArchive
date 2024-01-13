/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:57:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 16:53:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <string>

#define IDEA_SIZE 100

class Brain
{
public :
	Brain();
	Brain(const Brain& rhs);
	~Brain();

	Brain& operator=(const Brain& rhs);

	int	getIdeaSize() const { return IDEA_SIZE; }
	const std::string& getIdea(int idx) const;
	void setIdea(int idx, const std::string& idea);

private :
	std::string	m_Ideas[IDEA_SIZE];
};

#endif