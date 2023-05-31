/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:22:23 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        /* Functions */
        void        setTarget(std::string target);
        std::string getTarget(void) const;
        void        execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};

#endif