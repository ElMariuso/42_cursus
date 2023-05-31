/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:09 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 22:20:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
    /* Methods */
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& rhs);
        ~ClapTrap(void);
        /* Assignement Operators */
        ClapTrap& operator=(const ClapTrap& rhs);
        /* Functions */
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        /* Getter */
        std::string getName(void);
        int         getHitPoints(void);
        int         getEnergyPoints(void);
        int         getAttackDamage(void);
        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;
        /* Setter */
        void        setName(std::string name);
        void        setHitPoints(int hit_points);
        void        setEnergyPoints(int energy_points);
        void        setAttackDamage(int attack_damage);

    /* Attributes */
    private:
        std::string _name;
        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;
};

#endif