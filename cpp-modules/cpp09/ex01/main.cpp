/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:11:14 by root              #+#    #+#             */
/*   Updated: 2023/05/19 17:01:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw (std::runtime_error("Not enough arguments."));
        if (argc > 2)
            throw (std::runtime_error("Too many arguments."));
        
        /* Run */
        RPN reverser(argv[1]);
        std::cout << reverser.getResult() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}