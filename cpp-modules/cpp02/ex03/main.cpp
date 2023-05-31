/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:32:05 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 17:44:11 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
    Point a(4, 10);
	Point b(4, 6);
	Point c(10, 6);
	Point point(4.1, 6.1);

	std::cout << "The 3 corners of the triangle are:" << std::endl \
    << "a: [" << a.getX() << "," << a.getY() << "]" << std::endl \
    << "b: [" << b.getX() << "," << b.getY() << "]" << std::endl \
    << "c: [" << c.getX() << "," << c.getY() << "]" << std::endl << std::endl;
    
	std::cout << "The point searched is :" << std::endl \
    << "[" << point.getX() << "," << point.getY() << "]" << std::endl << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is in the triangle." << std::endl;
	else
		std::cout << "The point is not in the triangle." << std::endl;
    return 0;
}