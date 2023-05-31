/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:56:21 by root              #+#    #+#             */
/*   Updated: 2022/10/25 22:58:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>

int main()
{
    size_t size = 10;
    std::vector<int> test;

    std::cout << "--- Initialisation ---" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        test.push_back(i + 10);
        std::cout << test[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Search Good ---" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(test, 14);
        std::cout << "Value: " << *it << std::endl;
        std::cout << "Iterator: " << &*it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Search Wrong ---" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(test, 140);
        std::cout << "Value: " << *it << std::endl;
        std::cout << "Iterator: " << &*it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}