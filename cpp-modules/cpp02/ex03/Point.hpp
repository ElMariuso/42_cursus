/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:35:30 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 17:40:37 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    /* Methods */
    public:
        Point(void);
        Point(const float a, const float b);
        Point(const Point& rhs);
        ~Point(void);
        /* Assignement Operators */
        const Point&  operator=(const Point& rhs);
        /* Functions */
        /* Getter */
        Fixed getX(void) const;
        Fixed getY(void) const;

    /* Attributes */
    private:
        const Fixed _x;
        const Fixed _y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif