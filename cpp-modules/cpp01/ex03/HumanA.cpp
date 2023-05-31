#include "HumanA.hpp"

Weapon  default_weapon("default weapon");

HumanA::HumanA(): _weapon(default_weapon)
{
    this->_name = "default";
    std::cout << this->_name << " created!" << std::endl;
    return ;   
}

HumanA::HumanA(Weapon& weapon): _weapon(weapon)
{
    this->_name = "default";
    std::cout << this->_name << " created!" << std::endl;
    return ;   
}

HumanA::HumanA(std::string name, Weapon& weapon): _weapon(weapon)
{
    this->_name = name;
    std::cout << this->_name << " created!" << std::endl;
    return ;
}

HumanA::~HumanA()
{
    std::cout << this->_name << " destroyed!" << std::endl;
    return ;
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}