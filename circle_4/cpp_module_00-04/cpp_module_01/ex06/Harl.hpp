/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:57:04 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/06 01:55:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
public :
	void complain(std::string& level);

private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif