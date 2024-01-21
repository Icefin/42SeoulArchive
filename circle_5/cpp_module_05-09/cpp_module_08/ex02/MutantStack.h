/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:24:56 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 21:44:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public stack<T>
{
public :

public :
	MutantStack();
	MutantStack(const MutantStack& op);
	~MutantStack();
	MutantStack& operator=(const MutantStack& op);

	unsigned int size() const;
	typename T::iterator begin();
	typename T::iterator end();

private :
	unsigned int m_Size;
};

#endif