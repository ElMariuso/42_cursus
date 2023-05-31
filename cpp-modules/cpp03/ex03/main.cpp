/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:50:48 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/19 21:40:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "------Test for constructor-----" << std::endl;
	DiamondTrap	character1("DFLT-THX");
	DiamondTrap	character2(character1);
	DiamondTrap	character3("TESTAAAAAAH");
	DiamondTrap	character4;
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	std::cout <<std::endl;

	std::cout << "------Test for operator = -----" << std::endl;
	character2 = character3;
	character4 = character1;
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	std::cout <<std::endl;

	std::cout << "------Test for highFivesGuys -----" << std::endl;
	character1.highFivesGuys();
	character2.highFivesGuys();
	character3.highFivesGuys();
	character4.highFivesGuys();
	std::cout << std::endl;

	std::cout << "------Test for guardGate -----" << std::endl;
	character1.guardGate();
	character2.guardGate();
	character3.guardGate();
	character4.guardGate();
	std::cout << std::endl;

	std::cout << "------Test for attack -----" << std::endl;
	character1.attack("Target 1");
	character2.attack("Target 2");
	character3.attack("Target 3");
	character4.attack("Target 4");;
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	std::cout <<std::endl;

	std::cout << "------Test for takeDamage -----" << std::endl;
	character1.takeDamage(10);
	character2.takeDamage(20);
	character3.takeDamage(150);
	character4.takeDamage(110);
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	std::cout <<std::endl;

	std::cout << "------Test for beRepaired -----" << std::endl;
	character1.beRepaired(5);
	character2.beRepaired(20);
	character3.beRepaired(60);
	character4.beRepaired(2);
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	std::cout <<std::endl;

	std::cout << "------Test for whoAmI -----" << std::endl;
	character1.whoAmI();
	character2.whoAmI();
	character3.whoAmI();
	character4.whoAmI();
	std::cout << std::endl;

	std::cout << "------Test for energy -----" << std::endl;
	for (int i = 0; i < 100 ; i++)
	{
		character1.attack("René");
		character2.attack("Jeannette");
		character3.attack("Yvette");
		character4.attack("Yvonne");
	}
	std::cout << std::endl;

	std::cout << "------Test for destructor -----" << std::endl;
	return (0);   
}