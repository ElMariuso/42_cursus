/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:11:29 by root              #+#    #+#             */
/*   Updated: 2023/05/27 16:04:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Constuctor */
RPN::RPN(const std::string& calcul)
{
    /* Check right format */
    if (isCorrect(calcul) == false)
        throw (std::runtime_error("Bad format."));
    /* Parsing argument */
    this->_op = this->fillOperators(calcul);
    this->_nb = this->fillNumbers(calcul);
    if (this->_op.empty() || this->_nb.empty())
        throw (std::runtime_error("Bad arguments."));
    try
    {
        this->_result = this->calculResult();
    }
    catch (const std::exception& e)
    {
        throw (e);
    }
}

/* Copy */
RPN::RPN(const RPN& rhs) { *this = rhs; }

RPN& RPN::operator=(const RPN& rhs)
{
    if (*this == rhs)
        return (*this);
    this->_op = rhs._op;
    this->_nb = rhs._nb;
    this->_result = rhs._result;
    return (*this);
}

/* Destructor */
RPN::~RPN() {}

/* Operators */
bool RPN::operator==(const RPN& rhs) const { return (this->_op == rhs._op && this->_nb == rhs._nb && this->_result == rhs._result); }

/* Utils */
std::stack<char> RPN::fillOperators(const std::string& calcul)
{
    char                    c;
    std::stack<char> ret;

    for (int i = calcul.length(); i >= 0; --i)
    {
        c = calcul[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
            ret.push(c);
    }
    return (ret);
}

std::stack<int> RPN::fillNumbers(const std::string& calcul)
{
    char                c;
    std::stack<int>     ret;
    std::string         number;

    for (int i = calcul.length(); i >= 0; --i)
    {
        c = calcul[i];
        if (std::isdigit(c))
            number += c;
        else if (c == ' ')
        {
            if (!number.empty())
            {
                int num;
                
                num = std::atoi(number.c_str());
                ret.push(num);
                number.clear();
            }
        }
    }
    if (!number.empty())
    {
        int num;

        num = std::atoi(number.c_str());
        ret.push(num);
    }
    return (ret);
}

int RPN::calculResult()
{
    std::stack<int> result_stack;
    char            op;
    int             oper1;
    int             oper2;
    int             result;

    result_stack = this->_nb;
    while (!this->_op.empty())
    {
        op = this->_op.top();
        this->_op.pop();
        oper1 = result_stack.top();
        result_stack.pop();
        oper2 = result_stack.top();
        result_stack.pop();
        switch (op)
        {
            case '+':
                result = oper1 + oper2;
                break ;
            case '-':
                result = oper1 - oper2;
                break ;
            case '*':
                result = oper1 * oper2;
                break ;
            case '/':
                if (oper2 != 0)
                    result = oper1 / oper2;
                else
                    throw (std::runtime_error("Bad division."));
                break ;
            default:
                throw (std::runtime_error("Invalid operator."));
        }
        result_stack.push(result);
    }
    if (result_stack.size() == 1)
        return (result_stack.top());
    else
        throw (std::runtime_error("Incorrect number of operations or numbers."));
}

/* Utils template */

template <typename T>
void RPN::printStack(const std::stack<T>& stack)
{
    std::stack<T>   copy_stack;
    T               element;

    copy_stack = stack;
    while (!copy_stack.empty())
    {
        element = copy_stack.top();
        std::cout << element << " ";
        copy_stack.pop();
    }
    std::cout << std::endl;   
}

/* Booleans */
bool RPN::isCorrect(const std::string& calcul)
{
    std::string number;
    bool        is_number;
    char        c;

    is_number = false;
    for (std::string::size_type i = 0; i < calcul.length(); ++i)
    {
        c = calcul[i];
        if (std::isdigit(c))
        {
            number += c;
            is_number = true;
        }
        else if (c == ' ')
        {
            if (is_number)
            {
                int num;

                num = std::atoi(number.c_str());
                if (num >= 10)
                    return (false);
                number.clear();
                is_number = false;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            is_number = false;
        else
            return (false);
    }
    if (is_number)
    {
        int num;

        num = std::atoi(number.c_str());
        if (num >= 10)
            return (false);
    }
    return (true);
}

/* Getter */
std::stack<char> RPN::getOperators() { return (this->_op); }
std::stack<int> RPN::getNumbers() { return (this->_nb); }
int RPN::getResult() { return (this->_result); }