/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:29:59 by root              #+#    #+#             */
/*   Updated: 2022/10/21 19:12:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{

}

Cure::Cure(const Cure& rhs): AMateria(rhs)
{
    *this = rhs;
}

Cure::~Cure()
{

}

Cure&   Cure::operator=(const Cure& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

/* Functions */

AMateria*   Cure::clone() const
{
    AMateria *ret = new Cure();
    return (ret);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}