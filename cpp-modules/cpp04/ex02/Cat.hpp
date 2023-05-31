/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:34:33 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:20:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(const Cat& rhs);
        virtual ~Cat(void);
        virtual Cat& operator=(const Cat& rhs);
        /* Functions */
        void            setBrain(Brain* brain);
        virtual Brain*  getBrain(void) const;
        virtual void    makeSound(void) const;
    
    private:
        Brain*  _brain;
};

#endif