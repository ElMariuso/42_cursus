/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:50:48 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/17 18:44:15 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    std::string s1("Gaston");
	std::string s2("Henry");
	ClapTrap paul(s1);
	ClapTrap henry(s2);

	paul.attack(s2);
	henry.takeDamage(paul.getAttackDamage());
	henry.beRepaired(10);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.beRepaired(1);
	henry.attack(s1);
	paul.takeDamage(henry.getAttackDamage());
	paul.attack(s2);
	paul.takeDamage(1);
	paul.beRepaired(1);   
}