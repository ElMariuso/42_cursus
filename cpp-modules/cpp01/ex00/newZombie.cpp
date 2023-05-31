#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *newZombax = new Zombie(name);
    return (newZombax);
}