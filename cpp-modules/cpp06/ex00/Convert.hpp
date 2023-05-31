/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:21:40 by root              #+#    #+#             */
/*   Updated: 2022/10/26 11:43:39 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <stdio.h>
# include <limits>
# include <climits>

class Convert
{
    public:
        /* Constructors and Destructors */
        Convert(void);
        Convert(std::string input);
        Convert(const Convert& rhs);
        ~Convert(void);
        /* Operators */
        Convert& operator=(const Convert& rhs);
        /* Exceptions */
        class InvalidInputException: public std::exception
        {
            public:
                const char* what(void) const throw();
        };
        /* Getter */
        std::string getInput(void) const;
        char        getChar(void) const;
        int         getInt(void) const;
        float       getFloat(void) const;
        double      getDouble(void) const;
        /* Setter */
        void        setInput(std::string input);
        void        setChar(char c);
        void        setInt(int i);
        void        setFloat(float f);
        void        setDouble(double d);
        /* Booleans */
        bool        isChar(std::string input);
        bool        isInt(std::string input);
        bool        isFloat(std::string input);
        bool        isDouble(std::string input);
        bool        isOther(std::string input);
        bool        isIntOverflow(void);
        /* Conversions */
        void        detectTypeAndConversion(void);

    private:
        std::string _input;
        char        _c;
        int         _i;
        float       _f;
        double      _d;
};

#endif