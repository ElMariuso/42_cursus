/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:21:57 by root              #+#    #+#             */
/*   Updated: 2022/10/26 11:43:31 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void)
{
    this->setInput("0");
}

Convert::Convert(std::string input)
{
    this->setInput(input);
    this->detectTypeAndConversion();
}

Convert::Convert(const Convert& rhs)
{
    *this = rhs;
}

Convert::~Convert(void)
{ }

/* Operators */

Convert&    Convert::operator=(const Convert& rhs)
{
    if (this != &rhs)
    {
        this->setInput(rhs.getInput());
        this->setChar(rhs.getChar());
        this->setInt(rhs.getInt());
        this->setFloat(rhs.getFloat());
        this->setDouble(rhs.getDouble());
    }
    return (*this);
}

/* Exceptions */

const char* Convert::InvalidInputException::what(void) const throw()
{
    return ("Invalid input");
}

/* Getter */

std::string Convert::getInput(void) const
{
    return (this->_input);
}

char    Convert::getChar(void) const
{
    return (this->_c);
}

int Convert::getInt(void) const
{
    return (this->_i);
}

float   Convert::getFloat(void) const
{
    return (this->_f);
}

double  Convert::getDouble(void) const
{
    return (this->_d);
}

/* Setter */

void    Convert::setInput(std::string input)
{
    this->_input = input;
}

void    Convert::setChar(char c)
{
    this->_c = c;
}

void    Convert::setInt(int i)
{
    this->_i = i;
}

void    Convert::setFloat(float f)
{
    this->_f = f;
}

void    Convert::setDouble(double d)
{
    this->_d = d;
}

/* Booleans */

bool    Convert::isChar(std::string input)
{
    return (input.length() == 1 && isdigit(input[0]) == false);
}

bool    Convert::isInt(std::string input)
{
    int sign = 0;

    if (input == "-0")
        return (true);
    if (input[0] == '-')
        sign++;
    if (input.length() != 1 && input[sign] == '0')
        return (false);
    for (int i = sign; (size_t)i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return (false);
    }
    return (true);
}

bool    Convert::isFloat(std::string input)
{
    int count_f = 0;
    int count_p = 0;
    int sign = 0;

    if (input.find('.') == std::string::npos || input.find('f') == std::string::npos)
        return (false);
    if (input[input.length() - 1] != 'f' && input[input.length() - 2] == '.' && input[0] == '.')
        return (false);
    if (input[0] == '-')
        sign++;
    if (input[sign] == '0' && input[sign + 1] != '.')
        return (false);
    for (int i = sign; (size_t)i < input.length(); i++)
    {
        if (isdigit(input[i]) == false && input[i] != '.' && input[i] != 'f')
            return (false);
        if (input[i] == 'f')
            count_f++;
        if (input[i] == '.')
            count_p++;
    }
    if (count_f > 1 || count_p > 1)
        return (false);
    return (true); 
}

bool    Convert::isDouble(std::string input)
{
    int count_p = 0;
    int sign = 0;

    if (input.find('.') == std::string::npos)
        return (false);
    if (input[input.length() - 1] == '.' && input[0] == '.')
        return (false);
    if (input[0] == '-')
        sign++;
    if (input[sign] == '0' && input[sign + 1] != '.')
        return (false);
    for (int i = sign; (size_t)i < input.length(); i++)
    {
        if (isdigit(input[i]) == false && input[i] != '.')
            return (false);
        if (input[i] == '.')
            count_p++;
    }
    if (count_p > 1)
        return (false);
    return (true);  
}

bool    Convert::isOther(std::string input)
{
    if (input != "-inff" && input != "+inff" && input != "nanf" && input != "-inf" && input != "+inf" && input != "nan")
        return (false);
    return (true);
}

bool    Convert::isIntOverflow(void)
{
    long    t;
    
    sscanf(this->_input.c_str(), "%lu", &t);
    if (t > INT_MAX)
        return (false);
    if (t < INT_MIN)
        return (false);
    return (true);
}

/* Conversions */

void    Convert::detectTypeAndConversion(void)
{
    if (this->isChar(this->getInput()))
    {
        this->setChar(static_cast<char>(this->_input[0]));
        this->setInt(static_cast<int>(this->_c));
        this->setFloat(static_cast<float>(this->_c));
        this->setDouble(static_cast<double>(this->_c));

        std::cout << "char: '" << this->_c << "'" << std::endl \
        << "int: " << this->_i << std::endl \
        << "float: " << this->_f << ".0f" << std::endl \
        << "double: " << this->_d << ".0" << std::endl;
    }
    else if (this->isInt(this->getInput()) && this->isIntOverflow())
    {
        sscanf(this->_input.c_str(), "%d", &this->_i);
        this->setChar(static_cast<char>(this->_i));
        this->setFloat(static_cast<float>(this->_i));
        this->setDouble(static_cast<double>(this->_i));

        if (isprint(this->_c))
            std::cout << "char: '" << this->_c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << this->_i << std::endl;
        std::cout << "float: " << this->_f << ".0f" << std::endl;
        std::cout << "double: " << this->_d << ".0" << std::endl;
    }
    else if (this->isFloat(this->getInput()))
    {
        sscanf(this->_input.c_str(), "%f", &this->_f);
        this->setChar(static_cast<char>(this->_f));
        this->setInt(static_cast<int>(this->_f));
        this->setDouble(static_cast<double>(this->_f));

        if (isprint(this->_c))
            std::cout << "char: '" << this->_c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << this->_i << std::endl \
        << "float: " << this->_f << "f" << std::endl \
        << "double: " << this->_d << std::endl;
    }
    else if (this->isDouble(this->getInput()))
    {
        sscanf(this->_input.c_str(), "%lf", &this->_d);
        this->setChar(static_cast<char>(this->_d));
        this->setInt(static_cast<int>(this->_d));
        this->setFloat(static_cast<float>(this->_d));

        if (isprint(this->_c))
            std::cout << "char: '" << this->_c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << this->_i << std::endl \
        << "float: " << this->_f << "f" << std::endl \
        << "double: " << this->_d << std::endl;
    }
    else if (this->isOther(this->getInput()))
    {
        if (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf")
        {
            std::cout << "char: impossible" << std::endl \
            << "int: impossible" << std::endl \
            << "float: " << this->_input << std::endl \
            << "double: " << this->_input.erase(this->_input.length() - 1) << std::endl;
        }
        else if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
        {
            std::cout << "char: impossible" << std::endl \
            << "int: impossible" << std::endl \
            << "float: " << this->_input + "f" << std::endl \
            << "double: " << this->_input << std::endl;
        }
        else
            throw (InvalidInputException());
    }
    else
        throw (InvalidInputException());
}