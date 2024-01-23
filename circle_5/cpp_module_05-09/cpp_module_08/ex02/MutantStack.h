/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:24:56 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/23 15:58:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public :
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

public :
	MutantStack() {};
	MutantStack(const MutantStack& op);
	~MutantStack() {};
	MutantStack& operator=(const MutantStack& op);

	iterator begin(void)
	{
		return (this->c.begin());
	}

	iterator end(void)
	{
		return (this->c.end());
	}

	const_iterator begin(void) const
	{
		return (this->c.begin());
	}

	const_iterator end(void) const
	{
		return (this->c.end());
	}

	reverse_iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend(void)
	{
		return (this->c.rend());
	}

	const_reverse_iterator rbegin(void) const
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rend(void) const
	{
		return (this->c.rend());
	}
};

#endif