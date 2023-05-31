/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:30:01 by root              #+#    #+#             */
/*   Updated: 2022/10/21 23:08:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int to_exec, int to_sign): _name(name), _to_exec(to_exec), _to_sign(to_sign), _is_signed(false)
{
    if (this->getToExec() < 1 || this->getToSign() < 1)
        throw (GradeTooHighException());
    else if (this->getToExec() > 150 || this->getToSign() > 150)
        throw (GradeTooLowException());
}

Form::Form(const Form& rhs): _name(rhs.getName()), _to_exec(rhs.getToExec()), _to_sign(rhs.getToSign()), _is_signed(rhs.getIsSigned())
{
    *this = rhs;
}

Form::~Form()
{

}

Form&   Form::operator=(const Form& rhs)
{
    (void)rhs;
    return (*this);
}

/* Functions */

const std::string Form::getName(void) const
{
    return (this->_name);
}

int Form::getToExec(void) const
{
    return (this->_to_exec);
}

int Form::getToSign(void) const
{
    return (this->_to_sign);
}

bool    Form::getIsSigned(void) const
{
    return (this->_is_signed);
}

void    Form::setIsSigned(bool is_signed)
{
    this->_is_signed = is_signed;
}

void    Form::beSigned(Bureaucrat& s)
{
    if (s.getGrade() <= this->getToSign() && this->getIsSigned() == false)
        this->setIsSigned(true);
    else if (this->getIsSigned() == true)
        throw (GradeTooHighException());
    else
        throw (GradeTooLowException());
}

std::ostream&   operator<<(std::ostream& stream, const Form& elem)
{
    stream << elem.getName() << ", form need " << elem.getToSign() << " to be signed and " \
    <<  elem.getToExec() << " to be executed.";
    if (elem.getIsSigned() == true)
        stream << "is signed!";
    else
        stream << "is not signed!";
    return (stream);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Error grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Error grade is too low!");
}