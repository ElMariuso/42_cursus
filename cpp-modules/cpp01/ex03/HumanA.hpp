#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
    /* Methods */
    public:
        HumanA();
        HumanA(Weapon& weapon);
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        /* Functions */
        void    attack();

    /* Attributes */
    private:
        std::string _name;
        Weapon&     _weapon;
};

#endif