/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:29:57 by root              #+#    #+#             */
/*   Updated: 2022/10/21 00:04:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure(const Cure& rhs);
        ~Cure();
        Cure& operator=(const Cure& rhs);
        /* Functions */
        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif