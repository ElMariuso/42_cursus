/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:25:05 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Form", 25, 5)
{
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs): Form(rhs)
{
    *this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    this->setTarget(rhs.getTarget());
    return (*this);
}

/* Functions */

void    PresidentialPardonForm::setTarget(std::string target)
{
    this->_target = target;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}