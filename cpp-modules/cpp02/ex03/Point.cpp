/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:33:42 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 17:40:30 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
    
}

Point::Point(const float a, const float b): _x(a), _y(b)
{

}

Point::Point(const Point& rhs): _x(rhs._x), _y(rhs._y)
{

}

Point::~Point(void)
{
    
}

/* Assignement Operators */

const Point&  Point::operator=(const Point& rhs)
{
    return (rhs);
}

/* Functions */

/* Getter */

Fixed Point::getX(void) const
{
    return (this->_x);
}

Fixed Point::getY(void) const
{
    return (this->_y);
}