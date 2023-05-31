/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:31:24 by root              #+#    #+#             */
/*   Updated: 2022/10/25 20:02:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void    swap(T& a, T& b)
{
    T tmp = b;
    
    b = a;
    a = tmp;
};
template <typename T>
T min(T& a, T& b)
{
    if (a > b)
        return (b);
    else if (a < b)
        return (a);
    return (b);
};
template <typename T>
T max(T& a, T& b)
{
    if (a < b)
        return (b);
    else if (a > b)
        return (a); 
    return (b);
};

#endif