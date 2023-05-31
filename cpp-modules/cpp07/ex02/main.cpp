/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:48:56 by root              #+#    #+#             */
/*   Updated: 2022/10/25 21:52:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "--- Initialisation ---" << std::endl;
    Array<int> numbers(10);
    Array<int> to_copy(10);
    int* mirror = new int[10];

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i;
        mirror[i] = i;
        to_copy[i] = 100;
    }

    std::cout << "--- Print ---" << std::endl;
    std::cout << "number: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << numbers[i] << "]";
    }
    std::cout << std::endl;
    std::cout << "mirror: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << mirror[i] << "]";
    }
    std::cout << std::endl;
    std::cout << "to_copy: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << to_copy[i] << "]";
    }
    std::cout << std::endl << std::endl;

    std::cout << "--- Copy ---" << std::endl;
    numbers = to_copy;
    std::cout << "number: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << numbers[i] << "]";
    }
    std::cout << std::endl;
    std::cout << "to_copy: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "[" << to_copy[i] << "]";
    }
    std::cout << std::endl;
    
    delete[] mirror;
    return (0);
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }