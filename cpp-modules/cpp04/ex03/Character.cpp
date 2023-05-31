/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:33:32 by root              #+#    #+#             */
/*   Updated: 2022/10/21 19:42:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    this->setName("Default Character");
    this->_index_unequip = 0;
    this->_index_inventory = 0;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 10000; i++)
        this->_unequiped_materia[i] = NULL;
}

Character::Character(std::string name)
{
    this->setName(name);
    this->_index_unequip = 0;
    this->_index_inventory = 0;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 10000; i++)
        this->_unequiped_materia[i] = NULL;
}

Character::Character(const Character& rhs)
{
    *this = rhs;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    for (int i = 0; i < 10000; i++)
    {
        if (this->_unequiped_materia[i])
            delete this->_unequiped_materia[i];
    }
}

Character&  Character::operator=(const Character& rhs)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    for (int i = 0; i < 10000; i++)
    {
        if (this->_unequiped_materia[i])
            delete this->_unequiped_materia[i];
    }
    this->setName(rhs.getName());
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = rhs._inventory[i];
    for (int i = 0; i < 10000; i++)
        this->_unequiped_materia[i] = rhs._unequiped_materia[i];
    return (*this);
}

/* Functions */

AMateria*    Character::getAMateria(int i) const
{
    return (this->_inventory[i]);
}

AMateria*    Character::getUnequiped(int i) const
{
    return (this->_unequiped_materia[i]);
}

void    Character::setName(std::string name)
{
    this->_name = name;
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void    Character::equip(AMateria* m)
{
    if (this->_index_inventory == 3)
        std::cout << "The inventory is full!" << std::endl;
    else
    {
        this->_inventory[this->_index_inventory] = m;
        this->_index_inventory++;
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 4)
        std::cout << "This slot doesn't exist!" << std::endl;
    else
    {
        if (this->_inventory[idx])
        {
            if (_index_unequip < 10000)
            {
                this->_unequiped_materia[this->_index_unequip] = this->_inventory[idx];
                this->_index_unequip++;
                this->_index_inventory--;
                this->_inventory[idx] = NULL;
            }
            else
                std::cout << "Can't unequip, the floor is full!" << std::endl;
        }
        else
            std::cout << "There is no materia here!" << std::endl;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 4)
        std::cout << "This slot doesn't exist!" << std::endl;
    else if (this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << "There is no materia here!" << std::endl;
}