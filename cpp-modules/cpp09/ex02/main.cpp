/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:12:49 by root              #+#    #+#             */
/*   Updated: 2023/05/28 16:35:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {   
        if (argc < 2)
            throw (std::runtime_error("Not enough arguments."));
        if (argc > 3001)
            throw (std::runtime_error("Too many arguments."));

        /* Run */
        PmergeMe    tester(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}