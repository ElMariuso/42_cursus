/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:16 by root              #+#    #+#             */
/*   Updated: 2022/10/21 23:11:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- Constructor with grade too high ---" << std::endl;
    try
    {
        Bureaucrat test1("AAAAAAAAH", 200);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Constructor with grade too low ---" << std::endl;
    try
    {
        Bureaucrat test2("AAAAAAAAH", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Too many promotions ---" << std::endl;
    {
        try
        {
            Bureaucrat testpromo("promo", 1);
            testpromo.promote();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Too many demote ---" << std::endl;
    {
        try
        {
            Bureaucrat testdemo("demo", 150);
            testdemo.demote();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Promotions ---" << std::endl;
    {
        try
        {
            Bureaucrat test("Bureaucrat-test", 100);
            std::cout << test << std::endl;
            test.promote();
            test.promote();
            test.promote();
            std::cout << test << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Not Promotions ---" << std::endl;
    {
        try
        {
            Bureaucrat test("Bureaucrat-test", 100);
            std::cout << test << std::endl;
            test.demote();
            test.demote();
            test.demote();
            std::cout << test << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
}