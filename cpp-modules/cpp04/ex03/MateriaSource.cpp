/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:34:39 by root              #+#    #+#             */
/*   Updated: 2022/10/21 19:16:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_inv[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
    *this = rhs;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inv[i])
            delete this->_inv[i];
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs)
{
    for (int i = 0; i < 4; i++)
        this->_inv[i] = rhs._inv[i];
    return (*this);
}

/* Functions */

void    MateriaSource::learnMateria(AMateria* n)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inv[i] == NULL)
        {
            this->_inv[i] = n;
            return ;
        }
    }
    delete n;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (type.compare(this->_inv[i]->getType()) == 0)
            return (this->_inv[i]->clone());
    }
    return (NULL);
}