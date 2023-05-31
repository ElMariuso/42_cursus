/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:47:44 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 17:39:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
    int i;
};

/* Other functions*/

uintptr_t   serialize(Data* ptr);
Data*       deserialize(uintptr_t raw);

#endif