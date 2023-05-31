/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:57:17 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 17:42:35 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float sign (Point p1, Point p2, Point p3)
{
    float   area;
    Fixed   tmp;

    tmp = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    area = tmp.toFloat();
    return (area);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   d1, d2, d3;
    bool    has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return (!(has_neg && has_pos));
}