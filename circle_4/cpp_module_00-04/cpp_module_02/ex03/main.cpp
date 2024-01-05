/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 17:31:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p);

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p(1, 1);

	if (bsp(a, b, c, p) == true)
		std::cout << "Point p is inside of Triangle abc\n";
	else
		std::cout << "Point p is outside of Triangle abc\n";
}