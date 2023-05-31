/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:12 by root              #+#    #+#             */
/*   Updated: 2022/10/24 12:12:18 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default Bureaucrat")
{
    this->setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade <= 150)
    {
        if (grade >= 1)
            this->setGrade(grade);
        else
            throw (GradeTooLowException());
    }
    else
        throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): _name(rhs._name)
{
    this->setGrade(rhs.getGrade());
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    (void)rhs;
    return (*this);
}
        
/* Functions */

const int&  Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

const std::string&  Bureaucrat::getName() const
{
    return (this->_name);
}

// void    Bureaucrat::setName(std::string name)
// {
//     this->_name = name;
// }

void    Bureaucrat::promote()
{
    if (this->getGrade() > 1)
        this->_grade--;
    else
        throw (GradeTooHighException());
}

void    Bureaucrat::demote()
{
    if (this->getGrade() < 150)
        this->_grade++;
    else
        throw (GradeTooLowException());
}

void    Bureaucrat::signForm(Form& s)
{
    try
    {
        s.beSigned(*this);
        std::cout << this->getName() << " signed " << s.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::string error = e.what();
        if (error.compare("Error grade is too low!") == 0)
			std::cerr << this->getName() << " couldn't signed " << s.getName() << " because grade is too low" << std::endl;
		else if (error.compare("Error grade is too high!") == 0)
			std::cerr << this->getName() << " couldn't signed " << s.getName() << " because is already signed" << std::endl;
		else
			std::cerr << this->getName() << " couldn't signed " << s.getName() << " because of an unknowm reason" << std::endl;
    }
}

void    Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::string error = e.what();
        if (error.compare("Error grade is too low!") == 0)
			std::cerr << this->getName() << " couldn't execute " << form.getName() << " because grade is too low" << std::endl;
		else if (error.compare("Error grade is too high!") == 0)
			std::cerr << this->getName() << " couldn't execute " << form.getName() << " because is already signed" << std::endl;
		else
			std::cerr << this->getName() << " couldn't execute " << form.getName() << " because of an unknowm reason" << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& stream, const Bureaucrat& elem)
{
    stream << elem.getName() << ", bureaucrat grade " << elem.getGrade();
    return (stream);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error grade is too low!");
}