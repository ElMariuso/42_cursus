/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:57:54 by root              #+#    #+#             */
/*   Updated: 2022/10/26 12:43:05 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>

template <typename T>
void    iter(T* array, size_t size, void (*func)(T&))
{
    if (!array || !func)
        return ;
    for (size_t i = 0; i < size; i++)
        func(array[i]); 
};

#endif