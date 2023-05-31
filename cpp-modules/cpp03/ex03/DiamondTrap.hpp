/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:31:51 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/18 16:25:25 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    /* Methods */
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& rhs);
        ~DiamondTrap(void);
        /* Assignement Operators */
        DiamondTrap& operator=(const DiamondTrap& rhs);
        /* Functions */
        void    attack(const std::string &target);
        void    whoAmI();

    /* Attributes */
    private:
        std::string _name;
};

#endif