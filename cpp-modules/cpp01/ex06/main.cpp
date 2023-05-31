#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Harl    Karen;
        Karen.complain(argv[1]);
        return (0);
    }
    else
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        return (1);
    }
    return (1);
}