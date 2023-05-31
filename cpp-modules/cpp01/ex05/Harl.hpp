#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class   Harl
{
    /* Methods */
    public:
        Harl(void);
        ~Harl(void);
        /* Functions */
        void    complain(std::string level);

    /* Attributes */
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif