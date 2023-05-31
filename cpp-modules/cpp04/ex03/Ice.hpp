/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:30:01 by root              #+#    #+#             */
/*   Updated: 2022/10/21 00:04:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(const Ice& rhs);
        ~Ice();
        Ice& operator=(const Ice& rhs);
        /* Functions */
        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif