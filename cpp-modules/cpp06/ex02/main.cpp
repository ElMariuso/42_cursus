/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:58 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 18:39:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *test = NULL;

    for (int i = 0; i < 10;  i++)
    {
        test = generate();
        identify(test);
        identify(*test);
        delete test;
        std::cout << std::endl;
    }
    return (0);
}