/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:59:26 by root              #+#    #+#             */
/*   Updated: 2022/10/26 20:45:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <iostream>
# include <cstddef>
# include <exception>
# include <vector>
# include <climits>

class Span
{
    public:
        /* Constructors and Destructors */
        Span(unsigned int n);
        Span(const Span& rhs);
        ~Span(void);
        /* Operators */
        Span& operator=(const Span& rhs);
        /* Exceptions */
        class NoSpaceLeftException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NoNumberException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        /* Getter */
        size_t  getCapacity(void) const;
        size_t  getSize(void) const;
        /* Setter */
        /* Functions */
        void    addNumber(int n);
        void    addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
        size_t  shortestSpan(void);
        size_t  longestSpan(void);

    private:
        size_t              _size;
        std::vector<int>    _content;
};

#endif