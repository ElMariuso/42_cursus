/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:48:12 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/18 15:24:14 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    /* Methods */
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& rhs);
        ~ScavTrap(void);
        /* Assignement Operators */
        ScavTrap& operator=(const ScavTrap& rhs);
        /* Functions */
        void    attack(const std::string& target);
        void    guardGate();
};

#endif