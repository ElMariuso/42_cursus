#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>
# include <map>

class   Harl
{
    /* Methods */
    public:
        Harl();
        ~Harl();
        /* Functions*/
        void    complain(std::string level);

    /* Attributes */
    private:
        void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);
};

#endif