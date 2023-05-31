/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:25:49 by root              #+#    #+#             */
/*   Updated: 2022/10/17 14:20:32 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = (nb << Fixed::_nbits);
}

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(nb * (1 << Fixed::_nbits));
}


Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* Assignement Operators */

Fixed&  Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
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

/* Other functions */

std::ostream&    operator<<(std::ostream& stream, const Fixed& elem)
{
    stream << elem.toFloat();
    return (stream);
}