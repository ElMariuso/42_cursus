/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:23:19 by root              #+#    #+#             */
/*   Updated: 2022/10/14 13:23:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    /* Methods */
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& rhs);
        /* Assignement Operators */
        Fixed& operator =(const Fixed& rhs);
        /* Functions */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    /* Attributes */
    private:
        int                 _value;
        static int const    _nbits = 8;
};

#endif