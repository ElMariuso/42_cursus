/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:50:48 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/18 13:50:38 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "------Test for constructor-----" << std::endl;
	ClapTrap	character1("T-411");
	ClapTrap	character2("L-542");
	ClapTrap	character3;
	ScavTrap	character4("P-8");
	ScavTrap	character5(character4);
	ScavTrap	character6("TE-897");
	ScavTrap	character7;
	std::cout << std::endl;
	// Look ok

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	character5.print_infos();
	character6.print_infos();
	character7.print_infos();

	std::cout << "------Test for operator = -----" << std::endl;
	character5 = character6;
	std::cout << std::endl;

	std::cout << "------Test for guardGate -----" << std::endl;
	character4.guardGate();
	character5.guardGate();
	character6.guardGate();
	character7.guardGate();
	std::cout << std::endl;

	std::cout << "------Test for attack -----" << std::endl;
	character4.attack("Target1");
	character5.attack("Target2");
	character6.attack("Target3");
	character1.attack("Target4");
	character3.attack("Target5");
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	character5.print_infos();
	character6.print_infos();
	character7.print_infos();

	std::cout << "------Test for takeDamage -----" << std::endl;
	character4.takeDamage(10);
	character5.takeDamage(20);
	character6.takeDamage(150);
	character3.takeDamage(110);
	character2.takeDamage(12);
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	character5.print_infos();
	character6.print_infos();
	character7.print_infos();

	std::cout << "------Test for beRepaired -----" << std::endl;
	character4.beRepaired(5);
	character5.beRepaired(20);
	character6.beRepaired(60);
	character1.beRepaired(2);
	character2.beRepaired(12);
	std::cout << std::endl;

	std::cout << "------Get infos----" << std::endl;
	character1.print_infos();
	character2.print_infos();
	character3.print_infos();
	character4.print_infos();
	character5.print_infos();
	character6.print_infos();
	character7.print_infos();

	std::cout << "------Test for energy -----" << std::endl;
	for (int i = 0; i < 50 ; i++)
	{
		character4.attack("Target1");
		character5.attack("Target2");
	}
	std::cout << std::endl;
	
	std::cout << "------Test for destructor -----" << std::endl;
	return (0);   
}