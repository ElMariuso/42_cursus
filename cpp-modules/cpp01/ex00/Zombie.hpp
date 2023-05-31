#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
    /* Methods */
    public:
        Zombie(); // Default Constructor
        Zombie(std::string name); // Constructor with name
        ~Zombie(); // Destructor
        /* Functions */
        void    announce(void);

    /* Attributes */
    private:
        std::string _name;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif