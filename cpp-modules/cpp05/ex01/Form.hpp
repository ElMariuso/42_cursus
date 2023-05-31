/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:30:04 by root              #+#    #+#             */
/*   Updated: 2022/10/21 23:03:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string name, int to_exec, int to_sign);
        Form(const Form& rhs);
        ~Form();
        Form& operator=(const Form& rhs);
        /* Exceptions */
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
        const std::string   getName(void) const;
        int                 getToExec(void) const;
        int                 getToSign(void) const;
        bool                getIsSigned(void) const;
        void                setIsSigned(bool is_signed);
        void                beSigned(Bureaucrat& s);
    
    private:
        const std::string   _name;
        const int           _to_exec;
        const int           _to_sign;
        bool                _is_signed;
};

std::ostream&   operator<<(std::ostream& stream, const Form& elem);

#endif