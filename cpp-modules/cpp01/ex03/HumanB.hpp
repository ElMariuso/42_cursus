#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
    /* Methods */
    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        /* Functions */
        void    attack();
        void    setWeapon(Weapon *weapon);
    
    /* Attributes */
    private:
        std::string _name;
        bool        _hasWeapon;
        Weapon      *_weapon;
};

#endif