/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:49:06 by root              #+#    #+#             */
/*   Updated: 2022/10/26 17:36:15 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>
# include <cstddef>
# include <exception>

template <typename T>
class Array
{
    public:
        /* Constructors and Destructors */
        Array<T>(void)
        {
            this->_size = 0;
            this->_array = NULL;
        }
        Array<T>(unsigned int n)
        {
            this->_size = n;
            this->_array = new T[n];
        }
        Array<T>(const Array& rhs)
        {
            this->_size = rhs._size;
            this->_array = new T[this->_size];
            for (size_t i = 0; i < this->_size; i++)
                this->_array[i] = rhs._array[i];
        }
        ~Array<T>(void)
        {
            delete[] this->_array;   
        }
        /* Operators */
        Array<T>&  operator=(const Array& rhs)
        {
            delete[] this->_array;
            this->_size = rhs._size;
            this->_array = new T[this->_size];
            for (size_t i = 0; i < this->_size; i++)
                this->_array[i] = rhs._array[i];
            return (*this);
        }
        T&      operator[](int i) const
        {
            if ((size_t)i >= this->_size|| i < 0)
                throw (OutOfRangeException());
            return (this->_array[i]);
        }
        /* Exceptions */
        class OutOfRangeException: public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("[ERROR]: Out of range!");
                }
        };
        /* Functions */
        unsigned int    size(void) const
        {
            return (this->_size);
        }

    private:
        unsigned int    _size;
        T*              _array;
};

#endif