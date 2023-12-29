/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:36 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 16:52:37 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p);

int main()
{
	Point a;
	Point b;
	Point c;
	Point p;

	std::cout << bsp(a, b, c, p) << std::endl;
}