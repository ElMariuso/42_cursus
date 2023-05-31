#include "HumanB.hpp"

HumanB::HumanB()
{
    this->_name = "default";
    this->_hasWeapon = false;
    std::cout << this->_name << " created!" << std::endl;
    return ;
}

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_hasWeapon = false;
    std::cout << this->_name << " created!" << std::endl;
    return ;
}

HumanB::~HumanB()
{
    std::cout << this->_name << " destroyed!" << std::endl;
    return ;
}

void    HumanB::attack()
{
    if (this->_hasWeapon == true)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " can't attack without a weapon." << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon *weapon)
{
    this->_hasWeapon = true;
    this->_weapon = weapon;
    std::cout << this->_name << " get a weapon." << std::endl;
    return ;
}