/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:12:10 by root              #+#    #+#             */
/*   Updated: 2023/05/28 18:54:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Constructor */
PmergeMe::PmergeMe(int argc, char **argv)
{
    clock_t start;
    clock_t end;
    double  duration_deque;
    double  duration_list;

    if (this->setDeque(argc, argv))
        throw (std::runtime_error("Bad arguments."));
    if (this->setList(argc, argv))
        throw (std::runtime_error("Bad arguments."));
    std::cout << "Before: ";
    this->printDeque(this->_inputd);
    start = clock();
    this->mergeInsertionSort(this->_inputd);
    end = clock();
    duration_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    start = clock();
    this->mergeInsertionSort(this->_inputl);
    end = clock();
    duration_list = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    this->printDeque(this->_inputd);
    std::cout << "Time to process a range of " << this->_inputd.size() \
    << " elements with std::[..] : " << std::fixed << duration_deque << " s" << std::endl;
    std::cout << "Time to process a range of " << this->_inputl.size() \
    << " elements with std::[..] : " << std::fixed << duration_list << " s" << std::endl;
}

/* Copy */
PmergeMe::PmergeMe(const PmergeMe& rhs) { *this = rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (*this == rhs)
        return (*this);
    this->_inputd = rhs._inputd;
    this->_inputl = rhs._inputl;
    return (*this);
}

/* Destructor */
PmergeMe::~PmergeMe() {}

/* Operators */
bool PmergeMe::operator==(const PmergeMe& rhs) const { return (this->_inputd == rhs._inputd && this->_inputl == rhs._inputl); }

/* Utils */
void PmergeMe::printDeque(std::deque<int> to_print)
{
    if (to_print.size() > 5)
    {
        for (std::size_t i = 0; i != 4; ++i)
            std::cout << to_print[i] << " ";
        std::cout << "[...]";
    }
    else
    {
        for (size_t i = 0; i < to_print.size(); ++i)
            std::cout << to_print[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList(std::list<int> to_print)
{
    if (to_print.size() > 5)
    {
        std::list<int>::iterator it;

        it = to_print.begin();
        for (std::size_t i = 0; i != 4; ++i)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << "[...]";
    }
    else
    {
        for (std::list<int>::iterator it = to_print.begin(); it != to_print.end(); ++it)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/* Algorithms */
template<typename Container>
void PmergeMe::mergeInsertionSort(Container& input)
{
    typedef typename Container::iterator    Iterator;

    Container                               left;
    Container                               right;
    Iterator                                it;
    Iterator                                leftIt;
    Iterator                                rightIt;

    if (input.size() <= 1)
        return ;
    if (input.size() <= 16) {
        std::list<typename Container::value_type>   tempList(input.begin(), input.end());
        tempList.sort();
        input.assign(tempList.begin(), tempList.end());
        return ;
    }
    it = input.begin();
    for (size_t i = 0; i < input.size() / 2; ++i)
    {
        left.push_back(*it);
        ++it;
    }
    for (; it != input.end(); ++it)
        right.push_back(*it);
    mergeInsertionSort(left);
    mergeInsertionSort(right);
    input.clear();
    leftIt = left.begin();
    rightIt = right.begin();
    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt < *rightIt)
        {
            input.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            input.push_back(*rightIt);
            ++rightIt;
        }
    }
    while (leftIt != left.end())
    {
        input.push_back(*leftIt);
        ++leftIt;
    }
    while (rightIt != right.end())
    {
        input.push_back(*rightIt);
        ++rightIt;
    }
}

/* Setter */
int PmergeMe::setDeque(int argc, char **argv)
{
    int             num;
    
    for (int i = 1; i < argc; ++i)
    {
        num = std::atoi(argv[i]);
        if (num > 0 || std::strcmp(argv[i], "0") == 0)
            this->_inputd.push_back(num);
        else
            return (1);
    }
    return (0);
}

int PmergeMe::setList(int argc, char **argv)
{
    int             num;

    for (int i = 1; i < argc; ++i)
    {
        num = std::atoi(argv[i]);
        if (num > 0 || std::strcmp(argv[i], "0") == 0)
            this->_inputl.push_back(num);
        else
            return (1);
    }
    return (0);
}

/* Getter */
std::deque<int> PmergeMe::getDeque() { return (this->_inputd); }
std::list<int> PmergeMe::getList() { return (this->_inputl); } 