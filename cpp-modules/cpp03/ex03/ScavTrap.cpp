/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:47:58 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/19 15:51:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("default_name")
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap constructor called! " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap constructor called! " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs): ClapTrap(rhs)
{
    *this = rhs;
    std::cout << "ScavTrap copy constructor called! " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called! " << this->_name << std::endl;
}
        
/* Assignement Operators */
        
ScavTrap&   ScavTrap::operator=(const ScavTrap& rhs)
{
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
    return (*this);
}
        
/* Functions */

void    ScavTrap::attack(const std::string& target)
{
    if (this->getHitPoints() > 0)
    {
        if (this->getEnergyPoints() > 0)
        {
            this->setEnergyPoints(this->getEnergyPoints() - 1);
            std::cout << "ScavTrap " << this->getName() << " attacks " << target \
            << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        }
        else
            std::cout << this->getName() << " is too tired for doing anything." << std::endl;
    }
    else
    {
        std::cout << this->getName() << " is dead and can't do anything." << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << this->_name << " enter in guard mode!" << std::endl;
}