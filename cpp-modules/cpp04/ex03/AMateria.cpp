/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:19:01 by root              #+#    #+#             */
/*   Updated: 2022/10/21 18:53:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->setType(type);
}

AMateria::AMateria(const AMateria& rhs)
{
    *this = rhs;
}

AMateria::~AMateria(void)
{

}

AMateria&   AMateria::operator=(const AMateria& rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

AMateria&   AMateria::operator=(const AMateria* rhs)
{
    this->setType(rhs->getType());
    return (*this);
}

/* Functions */

void    AMateria::setType(std::string type)
{
    this->_type = type;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

// virtual AMateria*   clone() const = 0;

void    AMateria::use(ICharacter& target)
{
    (void)target;
}