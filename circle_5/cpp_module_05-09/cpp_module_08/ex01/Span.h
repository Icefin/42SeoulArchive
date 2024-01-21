/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 18:40:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <exception>

class Span
{
public :
	class OutOfRangeException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class TooFewElementException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	Span();
	Span(unsigned int N);
	Span(const Span& op);
	~Span();
	Span& operator=(const Span& op);

	void addNumber(int number);
	
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private :

};

#endif