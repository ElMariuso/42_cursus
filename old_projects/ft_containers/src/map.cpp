/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:16:48 by root              #+#    #+#             */
/*   Updated: 2023/02/18 00:44:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes.h *************************************************************** */

#include "ft_containers.hpp"

/* Functions **************************************************************** */

template <class Key, class T, class CompareSTD, class CompareFT>
std::string isEqual(std::map<Key, T, CompareSTD>& std_map, ft::map<Key, T, CompareFT>& ft_map)
{
    if (std_map.size() != ft_map.size())
        return ("✘");
    typename std::map<Key, T, CompareSTD>::iterator std_it = std_map.begin();
    typename ft::map<Key, T, CompareFT>::iterator ft_it = ft_map.begin();
    while (std_it != std_map.end() && ft_it != ft_map.end())
    {
        if (std_it->first != ft_it->first || std_it->second != ft_it->second)
            return ("✘");
        ++std_it;
        ++ft_it;
    }
    return ("✔");
}

template <class Key, class T, class CompareSTD, class CompareFT>
void    printMapAttributes(std::map<Key, T, CompareSTD>& std_map, ft::map<Key, T, CompareFT>& ft_map)
{
    if (std_map.empty())
        std::cout << "std_map is empty!" << std::endl;
    else
    {
        std::cout << "Printing std_map content: " << std::endl;
        typename std::map<Key, T, CompareSTD>::iterator std_it = std_map.begin();
        while (std_it != std_map.end())
        {
            std::cout << std_it->first << " => " << std_it->second;
            ++std_it;
            if (std_it != std_map.end())
                std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "End of std_map content!" << std::endl << std::endl;
    }
    if (ft_map.empty())
        std::cout << "ft_map is empty!" << std::endl;
    else
    {
        std::cout << "Printing ft_map content: " << std::endl;
        typename ft::map<Key, T, CompareFT>::iterator ft_it = ft_map.begin();
        while (ft_it != ft_map.end())
        {
            std::cout << ft_it->first << " => " << ft_it->second;
            ++ft_it;
            if (ft_it != ft_map.end())
                std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "End of ft_map content!" << std::endl << std::endl;
    }
}

void    map_constructor()
{
    std::cout << "/* Testing map constructor */" << std::endl;
    clock_t                                 start_time, end_time;
    std::map<int, int>                      std_map1;
    // std::map<int, int, std::greater<int> >  std_map2;
    ft::map<int, int>                       ft_map1;
    // ft::map<int, int, std::greater<int> >   ft_map2;

    std::cout << "std_map1 is empty: " << std_map1.empty() << std::endl;
    // std::cout << "std_map2 is empty: " << std_map2.empty() << std::endl;
    std::cout << "ft_map1 is empty: " << ft_map1.empty() << std::endl;
    // std::cout << "ft_map2 is empty: " << ft_map2.empty() << std::endl;

    start_time = clock();
    for (int i = 0; i < 20; i++)
        std_map1.insert(std::make_pair(i, i * 2));
    end_time = clock();
    std::cout << "Time taken by std::map1: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    for (int i = 0; i < 20; i++)
        ft_map1.insert(ft::make_pair(i, i * 2));
    end_time = clock();
    std::cout << "Time taken by ft::map1: " << (end_time - start_time) << " microseconds" << std::endl;

    // start_time = clock();
    // for (int i = 0; i < 20; i++)
    //     std_map2.insert(std::make_pair(i, i * 2));
    // end_time = clock();
    // std::cout << "Time taken by std::map2: " << (end_time - start_time) << " microseconds" << std::endl;

    // start_time = clock();
    // for (int i = 0; i < 20; i++)
    //     ft_map2.insert(ft::make_pair(i, i * 2));
    // end_time = clock();
    // std::cout << "Time taken by ft::map2: " << (end_time - start_time) << " microseconds" << std::endl;

    std::cout << "map1: " << std::endl;
    printMapAttributes<int, int, std::less<int>, ft::less<int> >(std_map1, ft_map1);
    std::cout << "Result1: " << isEqual<int, int, std::less<int>, ft::less<int> >(std_map1, ft_map1) << std::endl;

    // std::cout << "map2: " << std::endl;
    // printMapAttributes<int, int, std::greater<int>, std::greater<int> >(std_map2, ft_map2);
    // std::cout << "Result2: " << isEqual<int, int, std::greater<int>, std::greater<int> >(std_map2, ft_map2) << std::endl;
    std::cout << "/* Map constructor done */" << std::endl << std::endl;
}