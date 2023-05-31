/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:47:37 by root              #+#    #+#             */
/*   Updated: 2022/10/19 15:51:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("default_name")
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap constructor called! " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap constructor called! " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs): ClapTrap(rhs)
{
    *this = rhs;
    std::cout << "FragTrap copy constructor called! " << this->_name << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called! " << this->_name << std::endl;
}

/* Assignement Operators */

FragTrap&   FragTrap::operator=(const FragTrap& rhs)
{
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
    return (*this);
}

/* Functions */

void    FragTrap::attack(const std::string& target)
{
    if (this->getHitPoints() > 0)
    {
        if (this->getEnergyPoints() > 0)
        {
            this->setEnergyPoints(this->getEnergyPoints() - 1);
            std::cout << "FragTrap " << this->getName() << " attacks " << target \
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

void    FragTrap::highFivesGuys(void)
{
    std::cout << this->_name << " ask for high five!" << std::endl;
}