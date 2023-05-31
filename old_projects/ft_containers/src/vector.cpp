/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:16:50 by root              #+#    #+#             */
/*   Updated: 2023/02/17 22:51:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes.h *************************************************************** */

#include "ft_containers.hpp"

/* Functions **************************************************************** */

template <class T>
std::string isEqual(const std::vector<T>& std_vec, const ft::vector<T>& ft_vec)
{
    if (std_vec.size() != ft_vec.size())
        return ("✘");
    for (size_t i = 0; i < std_vec.size(); i++)
    {
        if (std_vec[i] != ft_vec[i])
            return ("✘");
    }
    return ("✔");
}

template <class T>
void    printVectorAttributes(std::vector<T>& std_vec, ft::vector<T>& ft_vec)
{
    if (std_vec.empty())
        std::cout << "std_vec is empty!" << std::endl;
    else
    {
        std::cout << "Printing std_vec content: " << std::endl;
        typename std::vector<T>::iterator std_it = std_vec.begin();
        while (std_it != std_vec.end())
        {
            std::cout << *std_it;
            ++std_it;
            if (std_it != std_vec.end())
                std::cout << ",";
        }
        std::cout << std::endl;
        std::cout << "End of std_vec content!" << std::endl << std::endl;
    }
    if (ft_vec.empty())
        std::cout << "ft_vec is empty!" << std::endl;
    else
    {
        std::cout << "Printing ft_vec content: " << std::endl;
        typename ft::vector<T>::iterator ft_it = ft_vec.begin();
        while (ft_it != ft_vec.end())
        {
            std::cout << *ft_it;
            ++ft_it;
            if (ft_it != ft_vec.end())
                std::cout << ",";
        }
        std::cout << std::endl;
        std::cout << "End of ft_vec content!" << std::endl << std::endl;
    }
}

void    vector_constructor()
{
    std::cout << "/* Testing constructor vector */" << std::endl;
    clock_t start_time, end_time;
    
    start_time = clock();
    std::vector<int> std_vector;
    for (int i = 0; i < 100; i++)
        std_vector.push_back(i);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft::vector<int> ft_vector;
    for (int i = 0; i < 100; i++)
        ft_vector.push_back(i);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes<int>(std_vector, ft_vector);
    std::cout << "Result: " << isEqual<int>(std_vector, ft_vector) << std::endl;
    std::cout << "/* Vector constructor done */" << std::endl << std::endl;
}

void    vector_constructor_value()
{
    std::cout << "/* Testing constructor with value vector */" << std::endl;
    clock_t     start_time, end_time;
    const int   size = 100;
    const int   val = 42;

    start_time = clock();
    std::vector<int> std_vec(size, val);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft::vector<int> ft_vec(size, val);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;
    
    printVectorAttributes<int>(std_vec, ft_vec);
    std::cout << "Result: " << isEqual<int>(std_vec, ft_vec) << std::endl;
    std::cout << "/* Vector constructor with value done */" << std::endl << std::endl;
}

void    vector_constructor_iterator()
{
    std::cout << "/* Testing vector constructor with iterator */" << std::endl;
    clock_t     start_time, end_time;
    std::vector<int> values;
    for (int i = 0; i < 10; i++)
        values.push_back(i + 80);

    start_time = clock();
    std::vector<int> std_vec(values.begin(), values.end());;
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft::vector<int> ft_vec(values.begin(), values.end());;
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes<int>(std_vec, ft_vec);
    std::cout << "Result: " << isEqual<int>(std_vec, ft_vec) << std::endl;
    std::cout << "/* Vector constructor with iterator done */" << std::endl << std::endl;
}

void    vector_copy_constructor()
{
    std::cout << "/* Testing copy constructor */" << std::endl;
    clock_t     start_time, end_time;
    std::vector<int> original_std_vector;
    original_std_vector.push_back(1);
    original_std_vector.push_back(2);
    original_std_vector.push_back(3);

    start_time = clock();
    std::vector<int> std_vector(original_std_vector);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    ft::vector<int> original_ft_vector;
    original_ft_vector.push_back(1);
    original_ft_vector.push_back(2);
    original_ft_vector.push_back(3);

    start_time = clock();
    ft::vector<int> ft_vector(original_ft_vector);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes<int>(std_vector, ft_vector);
    std::cout << "Result: " << isEqual<int>(std_vector, ft_vector) << std::endl;
    std::cout << "/* Copy constructor done */" << std::endl << std::endl;
}

void    vector_operator_assignement()
{
    std::cout << "/* Testing operator= */" << std::endl;
    clock_t     start_time, end_time;

    start_time = clock();
    std::vector<int>    std_vector_1(100);
    for (size_t i = 0; i < std_vector_1.size(); i++)
        std_vector_1[i] = i;
    std::vector<int>    std_vector_2(50);
    std_vector_2 = std_vector_1;
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft::vector<int>     ft_vector_1(100);
    for (size_t i = 0; i < ft_vector_1.size(); i++)
        ft_vector_1[i] = i;
    ft::vector<int>     ft_vector_2(50);
    ft_vector_2 = ft_vector_1;
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;
    
    printVectorAttributes<int>(std_vector_2, ft_vector_2);
    std::cout << "Result: " << isEqual<int>(std_vector_2, ft_vector_2) << std::endl;
    std::cout << "/* Operator= done */" << std::endl << std::endl;
}

void    vector_assign_range()
{
    std::cout << "/* Testing assign range */" << std::endl;
    clock_t             start_time, end_time;
    std::vector<int>    std_vector;
    std::vector<int>    std_vector2;
    ft::vector<int>     ft_vector;
    ft::vector<int>     ft_vector2;

    for (int i = 0; i < 10; i++) {
        std_vector.push_back(i);
        ft_vector.push_back(i);
    }
    for (int i = 10; i < 20; i++) {
        std_vector2.push_back(i);
        ft_vector2.push_back(i);
    }

    start_time = clock();
    std_vector.assign(std_vector2.begin(), std_vector2.end());
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vector.assign(ft_vector2.begin(), ft_vector2.end());
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vector, ft_vector);
    std::cout << "Result: " << isEqual(std_vector, ft_vector) << std::endl;
    std::cout << "/* Assign range done */" << std::endl << std::endl;
}

void    vector_assign_value()
{
    std::cout << "/* Testing assign value */" << std::endl;
    clock_t             start_time, end_time;
    std::vector<int>    std_vector;
    ft::vector<int>     ft_vector;
    for (int i = 0; i < 100; i++)
    {
        std_vector.push_back(i);
        ft_vector.push_back(i);
    }
    
    start_time = clock();
    std_vector.assign(4, 10);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vector.assign(4, 10);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;
    
    printVectorAttributes(std_vector, ft_vector);
    std::cout << "Result: " << isEqual(std_vector, ft_vector) << std::endl;
    std::cout << "/* Assign value done */" << std::endl << std::endl;
}

void    vector_at()
{
    std::cout << "/* Testing at */" << std::endl;
    clock_t             start_time, end_time;

    std::vector<int> std_vec;
    for (int i = 0; i < 1000; i++)
        std_vec.push_back(i);
    start_time = clock();
    int std_value = std_vec.at(500);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    ft::vector<int> ft_vec;
    for (int i = 0; i < 1000; i++)
        ft_vec.push_back(i);
    start_time = clock();
    int ft_value = ft_vec.at(500);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    std::cout << "std::vector value at position 500: " << std_value << std::endl;
    std::cout << "ft::vector value at position 500: " << ft_value << std::endl;
    std::cout << "Result: " << (std_value == ft_value) << std::endl;
    std::cout << "/* at done */" << std::endl << std::endl;
}

void    vector_operator_brackets()
{
    std::cout << "/* Testing operator[] */" << std::endl;
    std::vector<int> std_vector(10, 42);
    ft::vector<int> ft_vector(10, 42);

    for (size_t i = 0; i < std_vector.size(); i++)
    {
        std::cout << "std_vector[" << i << "] = " << std_vector[i] << ", ";
        std::cout << "ft_vector[" << i << "] = " << ft_vector[i] << std::endl;
        if (std_vector[i] != ft_vector[i])
        {
            std::cout << "Error: Values at index " << i << " are different." << std::endl;
            return ;
        }
    }
    std::cout << "/* Operator[] done */" << std::endl << std::endl;
}

void    vector_front()
{
    std::cout << "/* Testing vector front */" << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    for (int i = 0; i < 10; ++i) {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    std::cout << "std::vector front: " << std_vec.front() << std::endl;
    std::cout << "ft::vector front: " << ft_vec.front() << std::endl;

    if (std_vec.front() == ft_vec.front())
        std::cout << "Ok" << std::endl;
    else
        std::cout << "Failed" << std::endl;

    std::cout << "/* vector front done */" << std::endl << std::endl;
}

void    vector_back()
{
    std::cout << "/* Testing back() */" << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    std::cout << "std_vec.back() returns: " << std_vec.back() << std::endl;
    std::cout << "ft_vec.back() returns: " << ft_vec.back() << std::endl;
    std::cout << "Result: " << (std_vec.back() == ft_vec.back()) << std::endl;
    std::cout << "/* back() done */" << std::endl << std::endl;
}

void    vector_rbegin()
{
    std::cout << "/* Testing rbegin */" << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    bool result = true;

    std::vector<int>::reverse_iterator std_it = std_vec.rbegin();
    ft::vector<int>::reverse_iterator ft_it = ft_vec.rbegin();

    for (; std_it != std_vec.rend(); ++std_it, ++ft_it)
    {
        if (*std_it != *ft_it)
        {
            result = false;
            break;
        }
    }

    std::cout << "Result: " << result << std::endl;
    std::cout << "/* rbegin done */" << std::endl << std::endl;
}

void    vector_rend()
{
    std::cout << "/* Testing rend */" << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    bool result = true;

    std::vector<int>::reverse_iterator std_it = std_vec.rend();
    ft::vector<int>::reverse_iterator ft_it = ft_vec.rend();

    for (; std_it != std_vec.rbegin(); --std_it, --ft_it)
    {
        if (*std_it != *ft_it)
        {
            result = false;
            break;
        }
    }

    std::cout << "Result: " << result << std::endl;
    std::cout << "/* rend done */" << std::endl << std::endl;
}

void    vector_empty()
{
    std::cout << "/* Testing empty */" << std::endl;
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;

    std::cout << "std::vector<int> is " << (std_vector.empty() ? "empty" : "not empty") << std::endl;
    std::cout << "ft::vector<int> is " << (ft_vector.empty() ? "empty" : "not empty") << std::endl;

    std_vector.push_back(42);
    ft_vector.push_back(42);

    std::cout << "std::vector<int> is " << (std_vector.empty() ? "empty" : "not empty") << std::endl;
    std::cout << "ft::vector<int> is " << (ft_vector.empty() ? "empty" : "not empty") << std::endl;

    std::cout << "/* Empty done */" << std::endl << std::endl;
}

void    vector_size()
{
    std::cout << "/* Testing size */" << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    std::cout << "Size of an empty vector :" << std::endl;
    std::cout << "std::vector: " << std_vec.size() << std::endl;
    std::cout << "ft::vector : " << ft_vec.size() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    std::cout << "Size of a vector with 10 elements:" << std::endl;
    std::cout << "std::vector: " << std_vec.size() << std::endl;
    std::cout << "ft::vector : " << ft_vec.size() << std::endl;

    std_vec.pop_back();
    ft_vec.pop_back();

    std::cout << "Size of a vector with 9 elements:" << std::endl;
    std::cout << "std::vector: " << std_vec.size() << std::endl;
    std::cout << "ft::vector : " << ft_vec.size() << std::endl;
    
    std::cout << "/* Size done */" << std::endl << std::endl;
}

void    vector_capacity()
{
    std::cout << "/* Testing capacity */" << std::endl;
    clock_t             start_time, end_time;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    for (int i = 0; i < 10; i++)
    {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }
    
    std::cout << "std::vector capacity: " << std_vec.capacity() << std::endl;
    std::cout << "ft::vector capacity: " << ft_vec.capacity() << std::endl;
    
    start_time = clock();
    std_vec.reserve(20);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.reserve(20);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    std::cout << "ft::vector capacity after reserve: " << ft_vec.capacity() << std::endl;
    std::cout << "std::vector capacity after reserve: " << std_vec.capacity() << std::endl;
    std::cout << "Result: " << (ft_vec.capacity() == std_vec.capacity()) << std::endl;
    std::cout << "/* Capacity done */" << std::endl << std::endl;
}

void    vector_clear()
{
    std::cout << "/* Testing clear() */" << std::endl;
    clock_t             start_time, end_time;

    std::vector<int> std_vec;
    for (int i = 0; i < 1000; ++i) {
        std_vec.push_back(i);
    }
    start_time = clock();
    std_vec.clear();
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;
    std::cout << "Size of std::vector after clear: " << std_vec.size() << std::endl;

    ft::vector<int> ft_vec;
    for (int i = 0; i < 1000; ++i) {
        ft_vec.push_back(i);
    }
    start_time = clock();
    ft_vec.clear();
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;
    std::cout << "Size of ft::vector after clear: " << ft_vec.size() << std::endl;

    std::cout << "/* clear() done */" << std::endl << std::endl;
}

void    vector_insert_mono()
{
    std::cout << "/* Testing insert mono */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> std_vec(3, 100);
    ft::vector<int> ft_vec(3, 100);
    std::vector<int>::iterator std_it = std_vec.begin() + 2;
    ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;

    start_time = clock();
    std_vec.insert(std_it, 200);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.insert(ft_it, 200);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* insert mono done */" << std::endl << std::endl;
}

void    vector_insert_multi()
{
    std::cout << "/* Testing insert multi */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> std_vec(3, 100);
    ft::vector<int> ft_vec(3, 100);
    std::vector<int>::iterator std_it = std_vec.begin() + 2;
    ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;

    start_time = clock();
    std_vec.insert(std_it, 10, 200);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.insert(ft_it, 10, 200);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* insert multi done */" << std::endl << std::endl;
}

void    vector_insert_range()
{
    std::cout << "/* Testing insert range */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> values(5, 8421);
    std::vector<int> std_vec(3, 100);
    ft::vector<int> ft_vec(3, 100);
    std::vector<int>::iterator std_it = std_vec.begin() + 2;
    ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;

    start_time = clock();
    std_vec.insert(std_it, values.begin(), values.end());
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.insert(ft_it, values.begin(), values.end());
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* insert range done */" << std::endl << std::endl;
}

void    vector_erase()
{
    std::cout << "/* Testing erase */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    for (int i = 0; i < 1000; ++i) {
        std_vec.push_back(i);
        ft_vec.push_back(i);
    }

    std::vector<int>::iterator std_it = std_vec.begin() + 2;
    ft::vector<int>::iterator ft_it = ft_vec.begin() + 2;

    start_time = clock();
    std_vec.erase(std_it);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.erase(ft_it);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* erase done */" << std::endl << std::endl;
}

void    vector_erase_range()
{
    std::cout << "/* Testing erase range */" << std::endl;
    clock_t start_time, end_time;

    std::vector<int> std_vec(5, 100);
    std_vec[2] = 200;
    std_vec[3] = 300;
    ft::vector<int> ft_vec(5, 100);
    ft_vec[2] = 200;
    ft_vec[3] = 300;

    std::vector<int>::iterator std_first = std_vec.begin() + 1;
    std::vector<int>::iterator std_last = std_vec.begin() + 4;
    ft::vector<int>::iterator ft_first = ft_vec.begin() + 1;
    ft::vector<int>::iterator ft_last = ft_vec.begin() + 4;

    start_time = clock();
    std_vec.erase(std_first, std_last);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.erase(ft_first, ft_last);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* erase range done */" << std::endl << std::endl;
}

void    vector_push_back()
{
    std::cout << "/* Testing push_back */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        std_vec.push_back(i);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    for (int i = 0; i < 1000; i++)
        ft_vec.push_back(i);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* push_back done */" << std::endl << std::endl;
}

void    vector_pop_back()
{
    std::cout << "/* Testing pop_back */" << std::endl;
    clock_t start_time, end_time;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    std_vec.push_back(1);
    std_vec.push_back(2);
    std_vec.push_back(3);
    ft_vec.push_back(1);
    ft_vec.push_back(2);
    ft_vec.push_back(3);

    start_time = clock();
    std_vec.pop_back();
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.pop_back();
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* pop_back done */" << std::endl << std::endl;
}

void    vector_resize()
{
    std::cout << "/* Testing resize */" << std::endl;
    clock_t             start_time, end_time;
    std::vector<int>    std_vec(10, 100);
    ft::vector<int>     ft_vec(10, 100);

    start_time = clock();
    std_vec.resize(5);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec.resize(5);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec, ft_vec);
    std::cout << "Result: " << isEqual(std_vec, ft_vec) << std::endl;
    std::cout << "/* resize done */" << std::endl << std::endl;
}

void    vector_swap()
{
    std::cout << "/* Testing swap */" << std::endl;
    clock_t             start_time, end_time;
    std::vector<int>    std_vec1(3, 100);
    std::vector<int>    std_vec2(5, 200);
    ft::vector<int>     ft_vec1(3, 100);
    ft::vector<int>     ft_vec2(5, 200);

    start_time = clock();
    std_vec1.swap(std_vec2);
    end_time = clock();
    std::cout << "Time taken by std::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_vec1.swap(ft_vec2);
    end_time = clock();
    std::cout << "Time taken by ft::vector: " << (end_time - start_time) << " microseconds" << std::endl;

    printVectorAttributes(std_vec1, ft_vec1);
    printVectorAttributes(std_vec2, ft_vec2);
    std::cout << "Result 1: " << isEqual(std_vec1, ft_vec1) << std::endl;
    std::cout << "Result 2: " << isEqual(std_vec2, ft_vec2) << std::endl;
    std::cout << "/* swap done */" << std::endl << std::endl;
}

void    vector_relational_operators()
{
    std::cout << "/* Testing relational operators */" << std::endl;
    std::vector<int> std_vector_1;
    std::vector<int> std_vector_2;
    ft::vector<int>  ft_vector_1;
    ft::vector<int>  ft_vector_2;

    for (int i = 0; i < 10; i++)
    {
        std_vector_1.push_back(i);
        ft_vector_1.push_back(i);
    }
    std_vector_2 = std_vector_1;
    ft_vector_2 = ft_vector_1;

    std::cout << "vector1: " << std::endl;
    printVectorAttributes(std_vector_1, ft_vector_1);
    std::cout << "vector2: " << std::endl;
    printVectorAttributes(std_vector_2, ft_vector_2);

    std::cout << "std_vector_1 < std_vector_2 : " << (std_vector_1 < std_vector_2) << std::endl;
    std::cout << "std_vector_1 <= std_vector_2: " << (std_vector_1 <= std_vector_2) << std::endl;
    std::cout << "std_vector_1 > std_vector_2 : " << (std_vector_1 > std_vector_2) << std::endl;
    std::cout << "std_vector_1 >= std_vector_2: " << (std_vector_1 >= std_vector_2) << std::endl;
    std::cout << "std_vector_1 == std_vector_2: " << (std_vector_1 == std_vector_2) << std::endl;
    std::cout << "std_vector_1 != std_vector_2: " << (std_vector_1 != std_vector_2) << std::endl;

    std::cout << "ft_vector_1 < ft_vector_2 : " << (ft_vector_1 < ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 <= ft_vector_2: " << (ft_vector_1 <= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 > ft_vector_2 : " << (ft_vector_1 > ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 >= ft_vector_2: " << (ft_vector_1 >= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 == ft_vector_2: " << (ft_vector_1 == ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 != ft_vector_2: " << (ft_vector_1 != ft_vector_2) << std::endl;

    std_vector_1.pop_back();
    ft_vector_1.pop_back();
    std::cout << "vector1: " << std::endl;
    printVectorAttributes(std_vector_1, ft_vector_1);
    std::cout << "vector2: " << std::endl;
    printVectorAttributes(std_vector_2, ft_vector_2);

    std::cout << "std_vector_1 < std_vector_2 : " << (std_vector_1 < std_vector_2) << std::endl;
    std::cout << "std_vector_1 <= std_vector_2: " << (std_vector_1 <= std_vector_2) << std::endl;
    std::cout << "std_vector_1 > std_vector_2 : " << (std_vector_1 > std_vector_2) << std::endl;
    std::cout << "std_vector_1 >= std_vector_2: " << (std_vector_1 >= std_vector_2) << std::endl;
    std::cout << "std_vector_1 == std_vector_2: " << (std_vector_1 == std_vector_2) << std::endl;
    std::cout << "std_vector_1 != std_vector_2: " << (std_vector_1 != std_vector_2) << std::endl;

    std::cout << "ft_vector_1 < ft_vector_2 : " << (ft_vector_1 < ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 <= ft_vector_2: " << (ft_vector_1 <= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 > ft_vector_2 : " << (ft_vector_1 > ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 >= ft_vector_2: " << (ft_vector_1 >= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 == ft_vector_2: " << (ft_vector_1 == ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 != ft_vector_2: " << (ft_vector_1 != ft_vector_2) << std::endl;

    std_vector_1.push_back(10);
    std_vector_1.push_back(10);
    ft_vector_1.push_back(10);
    ft_vector_1.push_back(10);
    std::cout << "vector1: " << std::endl;
    printVectorAttributes(std_vector_1, ft_vector_1);
    std::cout << "vector2: " << std::endl;
    printVectorAttributes(std_vector_2, ft_vector_2);

    std::cout << "std_vector_1 < std_vector_2 : " << (std_vector_1 < std_vector_2) << std::endl;
    std::cout << "std_vector_1 <= std_vector_2: " << (std_vector_1 <= std_vector_2) << std::endl;
    std::cout << "std_vector_1 > std_vector_2 : " << (std_vector_1 > std_vector_2) << std::endl;
    std::cout << "std_vector_1 >= std_vector_2: " << (std_vector_1 >= std_vector_2) << std::endl;
    std::cout << "std_vector_1 == std_vector_2: " << (std_vector_1 == std_vector_2) << std::endl;
    std::cout << "std_vector_1 != std_vector_2: " << (std_vector_1 != std_vector_2) << std::endl;

    std::cout << "ft_vector_1 < ft_vector_2 : " << (ft_vector_1 < ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 <= ft_vector_2: " << (ft_vector_1 <= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 > ft_vector_2 : " << (ft_vector_1 > ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 >= ft_vector_2: " << (ft_vector_1 >= ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 == ft_vector_2: " << (ft_vector_1 == ft_vector_2) << std::endl;
    std::cout << "ft_vector_1 != ft_vector_2: " << (ft_vector_1 != ft_vector_2) << std::endl;

    std::cout << "/* Relational operators done */" << std::endl;
}