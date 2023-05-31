/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:32:58 by root              #+#    #+#             */
/*   Updated: 2022/10/21 18:06:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        Character(const Character& rhs);
        ~Character();
        Character& operator=(const Character& rhs);
        /* Functions */
        AMateria*           getAMateria(int i) const;
        AMateria*           getUnequiped(int i) const;
        void                setName(std::string name);
        std::string const & getName() const;
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);

    private:
        std::string _name;
        int         _index_unequip;
        int         _index_inventory;
        AMateria    *_unequiped_materia[10000];
        AMateria    *_inventory[4];
};

#endif