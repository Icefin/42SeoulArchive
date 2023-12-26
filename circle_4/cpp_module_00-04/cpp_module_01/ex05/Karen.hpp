/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:32:29 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/26 20:34:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class Karen
{
public :
	void complain(std::string level);

private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif