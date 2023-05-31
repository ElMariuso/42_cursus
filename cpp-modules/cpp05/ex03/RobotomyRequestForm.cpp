/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:24:17 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Form", 72, 45)
{
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs): Form(rhs)
{
    *this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    this->setTarget(rhs.getTarget());
    return (*this);
}

/* Functions */

void    RobotomyRequestForm::setTarget(std::string target)
{
    this->_target = target;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << this->getTarget() << " has been robotomized successfully by " << executor.getName() << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << this->getTarget() << " has failed sorry!" << std::endl; 
    }
}