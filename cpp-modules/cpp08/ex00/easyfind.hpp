/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:56:26 by root              #+#    #+#             */
/*   Updated: 2022/10/25 22:50:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <exception>

/* Exceptions */
class NumberNotFoundException: public std::exception
{
    public:
        char const* what() const throw()
        {
            return ("Number not found!");
        }
};

/* Template */
template <typename T>
typename T::iterator easyfind(T in, int i)
{
    typename T::iterator it = find(in.begin(), in.end(), i);
    if (it == in.end())
        throw (NumberNotFoundException());
    else
        return (it);
};

#endif