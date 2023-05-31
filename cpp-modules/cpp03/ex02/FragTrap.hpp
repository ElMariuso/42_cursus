/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:47:45 by root              #+#    #+#             */
/*   Updated: 2022/10/18 14:28:54 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    /* Methods */
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& rhs);
        ~FragTrap(void);
        /* Assignement Operators */
        FragTrap& operator=(const FragTrap& rhs);
        /* Functions */
        void    attack(const std::string& target);
        void    highFivesGuys(void);
};

#endif