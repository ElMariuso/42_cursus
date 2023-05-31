/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:11:27 by root              #+#    #+#             */
/*   Updated: 2023/05/27 16:03:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

/* Includes ***************************************************************** */

# include <stdexcept>
# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

/* Class ******************************************************************** */

class RPN
{
     /* Member functions ********************************************************* */
    public:
        /* Constructor */
        RPN(const std::string& calcul);

        /* Copy */
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);

        /* Destructor */
        ~RPN();

        /* Operators */
        bool operator==(const RPN& rhs) const;

        /* Utils */
        std::stack<char>    fillOperators(const std::string& calcul);
        std::stack<int>     fillNumbers(const std::string& calcul);
        int                 calculResult();
        
        /* Utils template */
        template <typename T>
        void                printStack(const std::stack<T>& stack);

        /* Booleans */
        bool                isCorrect(const std::string& calcul);

        /* Getter */
        std::stack<char>    getOperators();
        std::stack<int>     getNumbers();
        int                 getResult();
        
    /* Attributes *************************************************************** */
    private:
        std::stack<char>    _op;
        std::stack<int>     _nb;
        int                 _result;
};

#endif