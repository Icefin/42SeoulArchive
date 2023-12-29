/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:47:41 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 16:47:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public :
	Fixed(void);
	Fixed(const Fixed& rhs);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	Fixed& operator=(const Fixed& rhs);

private :
	static const int s_FractionalBits = 8;
	int m_Value;
};

#endif