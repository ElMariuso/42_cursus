/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:51:28 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:21:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat& rhs);
        ~WrongCat(void);
        WrongCat& operator=(const WrongCat& rhs);
        /* Functions */
        void    makeSound(void) const;
};

#endif