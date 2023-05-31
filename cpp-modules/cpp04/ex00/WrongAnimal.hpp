/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:51:59 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:21:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& rhs);
        ~WrongAnimal(void);
        WrongAnimal& operator=(const WrongAnimal& rhs);
        /* Functions */
        void        setType(std::string type);
        std::string getType(void) const;
        void        makeSound(void) const;
    protected:
        std::string type;
};

#endif