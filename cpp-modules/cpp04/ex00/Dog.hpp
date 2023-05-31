/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:38:49 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:21:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(const Dog& rhs);
        virtual ~Dog(void);
        virtual Dog& operator=(const Dog& rhs);
        /* Functions */
        virtual void    makeSound(void) const;
};

#endif