/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:13 by root              #+#    #+#             */
/*   Updated: 2023/05/18 13:32:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw (std::runtime_error("Not enough arguments."));
        if (argc > 2)
            throw (std::runtime_error("Too many arguments."));
        
        /* Run */
        BTC crypto_exchange(argv[1]);

        crypto_exchange.printAll();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}