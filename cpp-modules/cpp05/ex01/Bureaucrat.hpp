/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:14 by root              #+#    #+#             */
/*   Updated: 2022/10/24 12:09:15 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& rhs);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& rhs);
        /* Exceptions*/
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        /* Functions */
        const int&          getGrade() const;
        void                setGrade(int grade);
        const std::string&  getName() const;
        // void                setName(std::string name);
        void                promote();
        void                demote();
        void                signForm(Form& s);
        
    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream&   operator<<(std::ostream& stream, const Bureaucrat& elem);

#endif
