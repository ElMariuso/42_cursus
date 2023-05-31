/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:24:38 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        /* Functions */
        void        setTarget(std::string target);
        std::string getTarget(void) const;
        void        execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};

#endif