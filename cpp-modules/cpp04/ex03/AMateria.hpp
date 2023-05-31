/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:18:43 by root              #+#    #+#             */
/*   Updated: 2022/10/21 18:52:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& rhs);
        virtual ~AMateria(void);
        AMateria& operator=(const AMateria& rhs);
        AMateria& operator=(const AMateria* rhs);
        /* Functions */
        void                setType(std::string type);
        std::string const & getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);

    protected:
        std::string _type;
};

#endif