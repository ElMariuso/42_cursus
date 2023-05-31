#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
    /* Methods */
    public:
        Zombie(); // Constructor
        Zombie(std::string name); // Constructor with name
        ~Zombie(); // Destructor
        /* Functions */
        void    announce(void);
        void    set_name(std::string name);

    /* Attributes */
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);

#endif