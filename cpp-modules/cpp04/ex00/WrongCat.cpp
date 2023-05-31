/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:51:33 by root              #+#    #+#             */
/*   Updated: 2022/10/19 23:06:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
    this->setType("WrongCat");
    std::cout << this->type << " constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs): WrongAnimal()
{
    *this = rhs;
    std::cout << this->type << " copy constructor called!" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

void    WrongCat::makeSound(void) const
{
    std::cout << this->type << ": Meow meow!" << std::endl;
}