/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:47:28 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 17:39:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* Other functions*/

uintptr_t   serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}