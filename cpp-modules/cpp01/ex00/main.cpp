#include "Zombie.hpp"

int main(void)
{
    Zombie *newZombieO;

    newZombieO = newZombie("Arthas");
    randomChump("Kel'Thuzad");
    newZombieO->announce();
    delete newZombieO;
}