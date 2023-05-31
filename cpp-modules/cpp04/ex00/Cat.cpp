/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:34:23 by root              #+#    #+#             */
/*   Updated: 2022/10/19 23:04:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
    this->setType("Cat");
    std::cout << this->type << " constructor called!" << std::endl;
}

Cat::Cat(const Cat& rhs): Animal()
{
    *this = rhs;
    std::cout << this->type << " copy constructor called!" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << this->type << " destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

void    Cat::makeSound(void) const
{
    std::cout << this->type << ": Meow meow!" << std::endl;
}