#include "Harl.hpp"

int main()
{
    Harl Karen;

	std::cout << "Testing DEBUG level :" << std::endl;
	Karen.complain("DEBUG");
	std::cout << "Testing INFO level :" << std::endl;
	Karen.complain("INFO");
	std::cout << "Testing WARNING level :" << std::endl;
	Karen.complain("WARNING");
	std::cout << "Testing ERROR level :" << std::endl;
	Karen.complain("ERROR");
	std::cout << "Testing any random string :" << std::endl;
	Karen.complain("wefowhefiuwhr");
	std::cout << "Testing empty string :" << std::endl;
	Karen.complain("");
}