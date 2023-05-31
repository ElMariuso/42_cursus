#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Weapon created!" << std::endl;
    return ;
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
    std::cout << this->_type << " created!" << std::endl;
    return ;
}

Weapon::~Weapon()
{
    std::cout << this->_type << " destroyed!" << std::endl;
    return ;
}

std::string const & Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType(std::string name)
{
    std::cout << this->_type << " change his name for: " << name << std::endl;
    this->_type = name;
}