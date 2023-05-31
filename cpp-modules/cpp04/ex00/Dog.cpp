/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:38:38 by root              #+#    #+#             */
/*   Updated: 2022/10/19 23:05:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
    this->setType("Dog");
    std::cout << this->type << " constructor called!" << std::endl;
}

Dog::Dog(const Dog& rhs): Animal(rhs)
{
    *this = rhs;
    std::cout << this->type << " copy constructor called!" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << this->type << " destructor called!" << std::endl;
}

Dog&    Dog::operator=(const Dog& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

void    Dog::makeSound(void) const
{
    std::cout << this->type << ": Woof woof!" << std::endl;
}