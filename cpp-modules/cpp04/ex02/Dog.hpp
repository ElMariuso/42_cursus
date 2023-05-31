/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:38:49 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:20:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(const Dog& rhs);
        virtual ~Dog(void);
        virtual Dog& operator=(const Dog& rhs);
        /* Functions */
        void            setBrain(Brain* brain);
        virtual Brain*  getBrain(void) const;
        virtual void    makeSound(void) const;
        
    private:
        Brain*  _brain;
};

#endif