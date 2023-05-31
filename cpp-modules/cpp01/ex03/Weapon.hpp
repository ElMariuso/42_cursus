#ifndef WEAPON
# define WEAPON
# include <iostream>
# include <string>

class Weapon
{
    /* Methods */
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        /* Functions */
        std::string const & getType();
        void        setType(std::string name);

    /* Attributes */
    private:
        std::string _type;
};

#endif