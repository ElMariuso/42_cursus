#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << name << " is created." << std::endl;
    this->_name = name;
    return ;
}

Zombie::Zombie()
{
    this->_name = "Basic Zombie";
    std::cout << this->_name << " is created." << std::endl;
    return ;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is destroyed." << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}