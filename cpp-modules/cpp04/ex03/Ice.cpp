/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:30:06 by root              #+#    #+#             */
/*   Updated: 2022/10/21 19:12:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{

}

Ice::Ice(const Ice& rhs): AMateria(rhs)
{
    *this = rhs;
}

Ice::~Ice()
{

}

Ice&   Ice::operator=(const Ice& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

AMateria*   Ice::clone() const
{
    AMateria *ret = new Ice();
    return (ret);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}