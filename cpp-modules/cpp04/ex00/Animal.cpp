/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:26:25 by root              #+#    #+#             */
/*   Updated: 2022/10/20 19:54:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->setType("Animal");
    std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(std::string type)
{
    this->setType(type);
    std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
    *this = rhs;
    std::cout << "Animal copy constructor called!" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

void    Animal::setType(std::string type)
{
    this->type = type;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << this->type << " make a random sound." << std::endl;
}