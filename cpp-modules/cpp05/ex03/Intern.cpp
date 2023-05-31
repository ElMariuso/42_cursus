/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:13:33 by root              #+#    #+#             */
/*   Updated: 2022/10/22 16:05:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& rhs)
{
    *this = rhs;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

/* Functions */

Form*   Intern::makeForm(std::string form_name, std::string target)
{
    Form *ret;
    std::string form[3]= {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i;

    for (i = 0; i < 3; i++)
    {
        if (form_name == form[i])
            break ;
    }
    i++;
    switch (i)
    {
        case 1:
            ret = new ShrubberyCreationForm(target);
            break ;
        case 2:
            ret = new RobotomyRequestForm(target);
            break ;
        case 3:
            ret = new PresidentialPardonForm(target);
            break ;
        default:
            std::cout << "The form " << form_name << " doesn't exist!" << std::endl;
            return (NULL);
    }
    std::cout << "Intern create " << form_name << std::endl;
    return (ret);
}