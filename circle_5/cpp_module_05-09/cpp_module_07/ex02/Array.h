/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:12:53 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 21:41:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <exception>

template <typename T>
class Array
{
public :
	class OutOfRangeException : public std::exception
	{
	public :
		virtual const char* what() const throw()
		{
			return "OutOfRange";
		}
	};

public :
	Array()
		: m_Size(0)
	{
		m_Data = new T[m_Size];
	}

	Array(unsigned int n)
		: m_Size(n)
	{
		m_Data = new T[m_Size];
	}

	Array(const Array& op)
	{
		m_Size = op.m_Size;
		m_Size = new T[m_Size];
		for (unsigned int i = 0; i < m_Size; ++i)
			m_Data[i] = op.m_Data[i];
	}

	~Array()
	{
		delete[] m_Data;
	}

	Array& operator=(const Array& op)
	{
		delete[] m_Data;
		m_Size = op.m_Size;
		m_Data = new T[m_Size];
		for (unsigned int i = 0; i < m_Size; ++i)
			m_Data[i] = op.m_Data[i];
		return *this;
	}

	T& operator[](unsigned int idx)
	{
		if (idx < 0 || idx >= m_Size)
			throw(Array::OutOfRangeException());
		return m_Data[idx];
	}

	const T& operator[](unsigned int idx) const
	{
		if (idx < 0 || idx >= m_Size)
			throw(Array::OutOfRangeException());
		return m_Data[idx];
	}

	unsigned int size() const
	{
		return m_Size;
	}

private :
	T* 				m_Data;
	unsigned int 	m_Size;
};

#endif