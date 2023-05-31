/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:32:11 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 15:32:14 by mthiry           ###   ########.fr       */
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
        Fixed(void);
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed& rhs);
        ~Fixed(void);
        /* Assignement Operators */
        Fixed&  operator =(const Fixed& rhs);
        /* Comparison Operators */
        bool    operator>(const Fixed& rhs) const;
        bool    operator<(const Fixed& rhs) const;
        bool    operator>=(const Fixed& rhs) const;
        bool    operator<=(const Fixed& rhs) const;
        bool    operator==(const Fixed& rhs) const;
        bool    operator!=(const Fixed& rhs) const;
        /* Arithmetic Operators */
        Fixed   operator+(const Fixed& rhs);
        Fixed   operator-(const Fixed& rhs);
        Fixed   operator*(const Fixed& rhs);
        Fixed   operator/(const Fixed& rhs);
        /* Incrementation Operators*/
        Fixed&  operator++(void);
        Fixed&  operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);
        /* Functions */
        int                 getRawBits(void) const;
        void                setRawBits(int const raw);
        float               toFloat(void) const;
        int                 toInt(void) const;
        /* Min and Max */
        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

    /* Attributes */
    private:
        int                 _value;
        static int const    _nbits = 8;
};

/* Other functions */
std::ostream& operator<<(std::ostream& stream, const Fixed& elem);

#endif