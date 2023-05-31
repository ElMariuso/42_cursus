/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:31:40 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/19 15:59:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
    std::string name = "default_name";

    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_hit_points = this->FragTrap::_hit_points;
    this->_energy_points = 50;
    this->_attack_damage = this->FragTrap::_attack_damage;
    std::cout << "DiamondTrap constructor called! " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_hit_points = this->FragTrap::_hit_points;
    this->_energy_points = 50;
    this->_attack_damage = this->FragTrap::_attack_damage;
    std::cout << "DiamondTrap constructor called! " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs): ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
    *this = rhs;
    std::cout << "DiamondTrapTrap copy constructor called! " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called! " << this->_name << std::endl;
}

/* Assignement Operators */

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& rhs)
{
    this->_name = rhs._name;
    this->ClapTrap::_name = rhs._name + "_clap_name";
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    this->_attack_damage = rhs._attack_damage;
    return (*this);
}

/* Functions */

void		DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}
