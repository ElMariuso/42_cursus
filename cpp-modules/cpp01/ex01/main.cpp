#include "Zombie.hpp"

int main(void)
{
    int N = 10;
    Zombie *horde = zombieHorde(N, "Mega Zombie");

    for (int i = 0; i != N; i++)
        horde[i].announce();
    delete[] (horde);
}