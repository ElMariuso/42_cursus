/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:16 by root              #+#    #+#             */
/*   Updated: 2022/10/21 23:08:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- Construct some Bureaucrat ---" << std::endl;
    Bureaucrat  character1("Paul", 1);
	Bureaucrat  character2("Roger", 150);
    Form        form1("form", 20, 20);
    Form        form2("form2", 20, 20);
	std::cout << character1 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Grade too low for Forms ---" << std::endl;
    {
        try
        {
            Form form("test", 200, 200);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Grade too high for Forms ---" << std::endl;
    {
        try
	    {
		    Form form("test", 0, 12);
	    }
	    catch (const std::exception& e)
	    {
		    std::cerr << e.what() << std::endl;
	    }
    }
    std::cout << std::endl;

    std::cout << "--- Sign Form---" << std::endl;
	try
	{
		character1.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
	
    std::cout << "--- Failed to sign Form because grade too low ---" << std::endl;
	try
	{
		character2.signForm(form2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "--- Failed to sign Form because already signed ---" << std::endl;
    try
    {
        character1.signForm(form1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}