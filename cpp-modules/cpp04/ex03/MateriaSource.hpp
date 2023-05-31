/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:33:59 by root              #+#    #+#             */
/*   Updated: 2022/10/21 19:26:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& rhs);
        ~MateriaSource();
        MateriaSource& operator=(const MateriaSource& rhs);
        /* Functions */
        void        learnMateria(AMateria* n);
        AMateria*   createMateria(std::string const & type);
    
    private:
        AMateria* _inv[4];
};

#endif