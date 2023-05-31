/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:16 by root              #+#    #+#             */
/*   Updated: 2022/10/22 16:06:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "--- Constructors ---" << std::endl;
    Intern      one;
    Bureaucrat  two("Roger", 1);
    Form*       forms[3];
    std::cout << std::endl;

    std::cout << "--- Intern making Forms ---" << std::endl;
    forms[0] = one.makeForm("shrubbery creation", "home");
    forms[1] = one.makeForm("robotomy request", "Bender");
    forms[2] = one.makeForm("presidential pardon", "President");
    std::cout << std::endl;

    std::cout << "--- Bureaucrat sign Form ---" << std::endl;
    for (int i = 0; i < 3; i++)
        two.signForm(*forms[i]);
    std::cout << std::endl;

    std::cout << "--- Bureaucrat execute Form ---" << std::endl;
    for (int i = 0; i < 3; i++)
        two.executeForm(*forms[i]);
    std::cout << std::endl;

    std::cout << "--- Wrong makeForm ---" << std::endl;
    Form* fail = one.makeForm("aaaaaaaah", "bbbbbbbbbbbbbbb");
    (void)fail;
    std::cout << std::endl;
    
    std::cout << "--- Destructors ---" << std::endl;
    for (int i = 0; i < 3; i++)
        delete forms[i];
    return (0);
}