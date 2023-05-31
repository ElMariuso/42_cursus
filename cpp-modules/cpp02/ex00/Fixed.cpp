/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:23:11 by root              #+#    #+#             */
/*   Updated: 2022/10/14 13:23:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

/* Assignements Operators */

Fixed&  Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
}

/* Functions */

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}