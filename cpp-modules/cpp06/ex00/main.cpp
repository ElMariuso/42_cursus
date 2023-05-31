/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:13:06 by root              #+#    #+#             */
/*   Updated: 2022/10/25 16:02:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "[ERROR]: Invalid number of arguments!" << std::endl;
        return (1);
    }
    try
    {
        std::string arg = argv[1];
        Convert     in(arg);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}