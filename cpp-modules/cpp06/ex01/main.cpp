/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:05 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 17:41:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
    Data        *data = new Data;
    uintptr_t   uptr;

    data->i = 15;
    uptr = serialize(data);
    std::cout << "Before: " << data << std::endl << "Value: " << data->i << std::endl << std::endl;
    std::cout << "Serialization: " << uptr << std::endl << std::endl;
    std::cout << "Deserialization: " << deserialize(uptr) << std::endl << "Value: " << data->i << std::endl;

    delete data;
    return (0);   
}