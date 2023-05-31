/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:25:49 by root              #+#    #+#             */
/*   Updated: 2022/10/17 15:30:43 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_value = 0;
}

Fixed::Fixed(const int nb)
{
    this->_value = (nb << Fixed::_nbits);
}

Fixed::Fixed(const float nb)
{
    this->_value = roundf(nb * (1 << Fixed::_nbits));
}


Fixed::Fixed(const Fixed& rhs)
{
    *this = rhs;
}

Fixed::~Fixed(void)
{
}

/* Assignement Operators */

Fixed&  Fixed::operator=(const Fixed& rhs)
{
    this->_value = rhs.getRawBits();
    return (*this);
}

/* Comparison Operators */

bool    Fixed::operator>(const Fixed& rhs) const
{
    return (this->_value > rhs._value);
}

bool    Fixed::operator<(const Fixed& rhs) const
{
    return (this->_value < rhs._value);
}

bool    Fixed::operator>=(const Fixed& rhs) const
{
    return (this->_value >= rhs._value);
}

bool    Fixed::operator<=(const Fixed& rhs) const
{
    return (this->_value <= rhs._value);
}

bool    Fixed::operator==(const Fixed& rhs) const
{
    return (this->_value == rhs._value);
}

bool    Fixed::operator!=(const Fixed& rhs) const
{
    return (this->_value != rhs._value);
}

/* Arithmetic Operators */

Fixed   Fixed::operator+(const Fixed& rhs)
{
    Fixed result;

    result._value = this->_value + rhs._value;
    return (result);
}

Fixed   Fixed::operator-(const Fixed& rhs)
{
    Fixed result;

    result._value = this->_value - rhs._value;
    return (result);
}

Fixed   Fixed::operator*(const Fixed& rhs)
{
    Fixed   result;
    float   tmp;

    tmp = this->toFloat() * rhs.toFloat();
    result._value = (tmp * (1 << Fixed::_nbits));
    return (result);
}

Fixed   Fixed::operator/(const Fixed& rhs)
{
    Fixed   result;
    float   tmp;

    tmp = this->toFloat() / rhs.toFloat();
    result._value = (tmp * (1 << Fixed::_nbits));
    return (result);
}

/* Incrementation Operators*/

Fixed&  Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    
    ++this->_value;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    
    --this->_value;
    return (tmp);
}

/* Functions */

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float   Fixed::toFloat(void) const
{
    return ((float)this->_value / (float)(1 << Fixed::_nbits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> Fixed::_nbits);
}

/* Min and Max */

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed&    Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

/* Other functions */

std::ostream&    operator<<(std::ostream& stream, const Fixed& elem)
{
    stream << elem.toFloat();
    return (stream);
}