/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:51:26 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 18:36:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <cstddef>
# include <cstdlib>
# include <exception>

class Base
{
    public:
        virtual ~Base(void);
};

/* Other functions */

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif