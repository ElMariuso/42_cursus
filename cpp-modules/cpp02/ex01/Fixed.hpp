/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:25:42 by root              #+#    #+#             */
/*   Updated: 2022/10/14 13:33:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    /* Methods */
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed& rhs);
        ~Fixed();
        /* Assignement Operators */
        Fixed& operator =(const Fixed& rhs);
        /* Functions */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    /* Attributes */
    private:
        int                 _value;
        static int const    _nbits = 8;
};

/* Other functions */
std::ostream& operator<<(std::ostream& stream, const Fixed& elem);

#endif