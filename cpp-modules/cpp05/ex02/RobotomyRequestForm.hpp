/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:23:43 by root              #+#    #+#             */
/*   Updated: 2022/10/22 01:09:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        /* Functions */
        void        setTarget(std::string target);
        std::string getTarget(void) const;
        void        execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};

#endif