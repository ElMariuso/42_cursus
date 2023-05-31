/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:01:53 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:19:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& rhs);
        virtual ~Animal();
        virtual Animal& operator=(const Animal& rhs);
        /* Functions */
        void            setType(std::string type);
        std::string     getType(void) const;
        virtual Brain*  getBrain(void) const = 0;
        virtual void    makeSound(void) const = 0;
    protected:
        std::string type;
};

#endif