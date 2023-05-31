#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl \
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
    << std::endl;
}
void    Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl \
    << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" \
    << std::endl;
}

void    Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl \
    << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." \
    << std::endl;
}

void    Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl \
    << "This is unacceptable! I want to speak to the manager now." \
    << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i <= 4)
    {
        if (levels[i] == level)
        {
            i++;
            break ;
        }
        i++;
    }
    switch (i)
    {
        case 1:
            this->debug();
            break ;
        case 2:
            this->info();
            break ;
        case 3:
            this->warning();
            break ;
        case 4:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
}