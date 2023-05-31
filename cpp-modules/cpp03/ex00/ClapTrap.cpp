/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:00 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 22:21:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap constructor called!" << std::endl;
    this->setName("default_name");
    this->setHitPoints(10);
    this->setEnergyPoints(10);
    this->setAttackDamage(0);
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap constructor called!" << std::endl;
    this->setName(name);
    this->setHitPoints(10);
    this->setEnergyPoints(10);
    this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
    std::cout << "ClapTrap copy constructor called!" << std::endl;
    *this = rhs;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called!" << std::endl;
}

/* Assignement Operators */

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
    return (*this);
}

/* Functions */

void    ClapTrap::attack(const std::string& target)
{
    if (this->getHitPoints() > 0)
    {
        if (this->getEnergyPoints() > 0)
        {
            this->setEnergyPoints(this->getEnergyPoints() - 1);
            std::cout << "ClapTrap " << this->getName() << " attacks " << target \
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

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoints() > 0)
    {
        this->setHitPoints(this->getHitPoints() - amount);
        std::cout << "ClapTrap " << this->getName() << " take " << amount << " points of damage, and he's now at " \
        << this->getHitPoints() << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "Stop! " << this->getName() << " is already dead!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHitPoints() > 0)
    {
        if (this->getEnergyPoints() > 0)
        {
            this->setHitPoints(this->getHitPoints() + amount);
            this->setEnergyPoints(this->getEnergyPoints() - 1);
            std::cout << "ClapTrap " << this->getName() << " repaired himself with " << amount \
            << " points and he's now at " << this->getHitPoints() << " hit points!" << std::endl;
        }
        else
            std::cout << this->getName() << " is too tired for doing anything." << std::endl;
    }
    else
    {
        std::cout << this->getName() << " is dead and can't do anything." << std::endl;
    }
}

/* Getter */

std::string ClapTrap::getName(void)
{
    return (this->_name);
}

int ClapTrap::getHitPoints(void)
{
    return (this->_hit_points);
}

int ClapTrap::getEnergyPoints(void)
{
    return (this->_energy_points);
}

int ClapTrap::getAttackDamage(void)
{
    return (this->_attack_damage);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->_hit_points);
}

int ClapTrap::getEnergyPoints(void) const
{
    return (this->_energy_points);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->_attack_damage);
}

/* Setter */

void    ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void    ClapTrap::setHitPoints(int hit_points)
{
    this->_hit_points = hit_points;
}

void    ClapTrap::setEnergyPoints(int energy_points)
{
    this->_energy_points = energy_points;
}

void    ClapTrap::setAttackDamage(int attack_damage)
{
    this->_attack_damage = attack_damage;
}