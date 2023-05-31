/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:34:33 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:21:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(const Cat& rhs);
        virtual ~Cat(void);
        virtual Cat& operator=(const Cat& rhs);
        /* Functions */
        virtual void    makeSound(void) const;
};

#endif