/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:59:21 by root              #+#    #+#             */
/*   Updated: 2022/10/26 20:46:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Constructors and Destructors */

Span::Span(unsigned int n): _size(n)
{ }

Span::Span(const Span& rhs)
{
    *this = rhs;
}

Span::~Span(void)
{ }

/* Operators */

Span&   Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        this->_size = rhs._size;
        this->_content = rhs._content;
    }
    return (*this);
}

/* Exceptions */

const char* Span::NoSpaceLeftException::what() const throw()
{
    return ("No space left in the vector!");
}

const char* Span::NoNumberException::what() const throw()
{
    return ("Can't find a right number!");
}

/* Getter */

size_t  Span::getCapacity(void) const
{
    return (this->_size);
}

size_t  Span::getSize(void) const
{
    return (this->_content.size());
}

/* Setter */
/* Functions */

void    Span::addNumber(int n)
{
    if (this->_content.size() < this->_size)
        this->_content.push_back(n);
    else
        throw (NoSpaceLeftException());
}

void    Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (this->_content.size() + 1 >= this->_size)
        throw (NoSpaceLeftException());
    else
    {
        unsigned int    size = std::distance(first, last);
        for (unsigned int i = 0; i < size; i++)
        {
            this->_content.push_back(*(first + i));
            if (this->_content.size() >= this->_size)
                throw (NoSpaceLeftException());
        }
    }
}

size_t  Span::shortestSpan(void)
{
    if (this->_content.empty() || this->_content.size() < 2)
        throw (NoNumberException());

    size_t  ret = UINT_MAX;
    size_t  tmp_ret;
    std::vector<int> tmp = this->_content;
    std::sort (tmp.begin(), tmp.end());
    std::vector<int>::iterator it_start(this->_content.begin()), it_end(this->_content.end());
    while (it_start != it_end - 1)
    {
        tmp_ret = *(it_start + 1) - *it_start;
        if (tmp_ret < ret)
            ret = tmp_ret;
        it_start++;
    }
    return (ret);
}

size_t  Span::longestSpan(void)
{
    if (this->_content.empty() || this->_content.size() < 2)
        throw (NoNumberException());

    std::vector<int> tmp = this->_content;
    std::sort (tmp.begin(), tmp.end());

    size_t  min = *std::min_element(tmp.begin(), tmp.end());
    size_t  max = *std::max_element(tmp.begin(), tmp.end());
    return (max - min);
}