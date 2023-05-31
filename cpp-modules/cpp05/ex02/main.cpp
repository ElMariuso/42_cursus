/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:16 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:02:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "--- Constructors ---" << std::endl;
    Bureaucrat              character1("Paul", 1);
	Bureaucrat              character2("Roger", 150);
	ShrubberyCreationForm   shrubForm("Shrubbery");
	RobotomyRequestForm     robotForm("Robot");
	PresidentialPardonForm  pardonForm("Presidential");
    std::cout << std::endl;

    std::cout << "--- Character 1 sign ShrubForm ---" << std::endl;
	try
	{
		character1.signForm(shrubForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "--- Character 1 sign RobotForm ---" << std::endl;
    try
	{
		character1.signForm(robotForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "--- Character 1 sign PresidentialForm ---" << std::endl;
	try
	{
		character1.signForm(pardonForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;

	std::cout << "--- Character1 executing ShrubForm ---" << std::endl;
	try
	{
		character1.executeForm(shrubForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Character1 executing RobotForm ---" << std::endl;
	try
	{
		character1.executeForm(robotForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Character1 executing PresidentialForm ---" << std::endl;
	try
	{
		character1.executeForm(pardonForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
    return (0);
}