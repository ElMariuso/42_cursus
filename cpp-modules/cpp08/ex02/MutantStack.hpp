/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:57:53 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/26 15:22:47 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        typedef typename MutantStack::container_type::iterator                  iterator;
        typedef typename MutantStack::container_type::const_iterator            const_iterator;
        typedef typename MutantStack::container_type::reverse_iterator          reverse_iterator;
        typedef typename MutantStack::container_type::const_reverse_iterator    const_reverse_iterator;

        /* Constructors and Destructors */
        MutantStack(void): std::stack<T>() {};
        MutantStack(const MutantStack<T>& rhs): std::stack<T>(rhs) {};
        ~MutantStack(void) {};
        /* Operators */
        MutantStack<T>& operator=(const MutantStack<T>& rhs)
        {
            if (*this != rhs)
                std::stack<T>::operator=(rhs);
            return (*this);
        }
        /* Iterator */
        iterator    begin() { return (std::stack<T>::c.begin()); }
        iterator    end() { return (std::stack<T>::c.end()); }
        reverse_iterator    rbegin() { return (std::stack<T>::c.rbegin()); }
        reverse_iterator    rend() { return (std::stack<T>::c.rend()); }
};

#endif