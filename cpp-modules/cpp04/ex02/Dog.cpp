/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:38:38 by root              #+#    #+#             */
/*   Updated: 2022/10/20 21:07:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
    this->setType("Dog");
    this->_brain = new Brain();
    std::cout << this->type << " constructor called!" << std::endl;
}

Dog::Dog(const Dog& rhs): Animal(rhs)
{
    *this = rhs;
    std::cout << this->type << " copy constructor called!" << std::endl;
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << this->type << " destructor called!" << std::endl;
}

Dog&    Dog::operator=(const Dog& rhs)
{
    this->setType(rhs.getType());
    this->_brain = new Brain(rhs._brain);
    return (*this);
}

/* Functions */

void    Dog::setBrain(Brain* brain)
{
    this->_brain = brain;
}

Brain*  Dog::getBrain(void) const
{
    return (this->_brain);
}


void    Dog::makeSound(void) const
{
    std::cout << this->type << ": Woof woof!" << std::endl;
}