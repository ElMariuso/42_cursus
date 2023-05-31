/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:34:23 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:00:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
    this->setType("Cat");
    std::cout << "Test aaaaaaaah" << std::endl;
    this->_brain = new Brain();
    std::cout << this->type << " constructor called!" << std::endl;
}

Cat::Cat(const Cat& rhs): Animal()
{
    *this = rhs;
    std::cout << this->type << " copy constructor called!" << std::endl;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << this->type << " destructor called!" << std::endl;
}

Cat&    Cat::operator=(const Cat& rhs)
{
    this->setType(rhs.getType());
    this->_brain = new Brain(rhs._brain);
    return (*this);
}

/* Functions */

void    Cat::setBrain(Brain* brain)
{
    this->_brain = brain;
}

Brain*  Cat::getBrain(void) const
{
    return (this->_brain);
}

void    Cat::makeSound(void) const
{
    std::cout << this->type << ": Meow meow!" << std::endl;
}