/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:57:52 by root              #+#    #+#             */
/*   Updated: 2022/10/26 12:43:33 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include  <iostream>

void    more(int& i)
{
    i += 10;
}

void    more(char& i)
{
    i += 10;
}

void    more_string(std::string& i)
{
    i.append("hey");
}

int main()
{
    {
        std::cout << "--- Make an Int Array and display Infos ---" << std::endl;
        int size = 10;
        int *array = new int[size];

        for (int i = 0; i < size; i++)
            array[i] = i;
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
    
        std::cout << "--- After iter ---" << std::endl;
        iter(array, size, more);
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
        delete[] array;
    }
    {
        std::cout << "--- Make an Char Array and display Infos ---" << std::endl;
        int size = 10;
        char *array = new char[size];

        for (int i = 0; i < size; i++)
            array[i] = 'a' + i;
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
    
        std::cout << "--- After iter ---" << std::endl;
        iter(array, size, more);
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
        delete[] array;
    }
    {
        std::cout << "--- Make an String Array and display Infos ---" << std::endl;
        int size = 10;
        std::string *array = new std::string[size];

        for (int i = 0; i < size; i++)
            array[i] = "This is a word: ";
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
    
        std::cout << "--- After iter ---" << std::endl;
        iter(array, size, more_string);
        for (int i = 0; i < size; i++)
            std::cout << array[i] << std::endl;
        delete[] array;
    }
    return (0);
}

// class Awesome
// {
//     public:
//         Awesome(void): _n(42) { return; }
//         int get(void) const { return (this->_n); }
//     private:
//         int _n;
// };
// std::ostream& operator<<(std::ostream& o, Awesome const& rhs) { o << rhs.get(); return (o); }

// template <typename T>
// void print(T& x) { std::cout << x << std::endl; return;}

// int main()
// {
//     int tab[] = {0, 1, 2, 3, 4};
//     Awesome tab2[5];

//     iter(tab, 5, print);
//     iter(tab2, 5, print);

//     return (0);
// }