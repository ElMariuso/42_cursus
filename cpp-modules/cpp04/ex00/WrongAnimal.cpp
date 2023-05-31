/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:51:41 by root              #+#    #+#             */
/*   Updated: 2022/10/20 19:54:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->setType("WrongAnimal");
    std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->setType(type);
    std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
    *this = rhs;
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

void    WrongAnimal::setType(std::string type)
{
    this->type = type;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << this->type << " make a random sound." << std::endl;
}