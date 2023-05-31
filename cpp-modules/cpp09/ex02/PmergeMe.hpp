/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:12:08 by root              #+#    #+#             */
/*   Updated: 2023/05/28 18:34:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/* Includes ***************************************************************** */

# include <iostream>
# include <list>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <stdexcept>
# include <cstring>
# include <algorithm>

/* Class ******************************************************************** */

class PmergeMe
{
    /* Member functions ********************************************************* */
    public:
        /* Constructor */
        PmergeMe(int argc, char **argv);

        /* Copy */
        PmergeMe(const PmergeMe& rhs);
        PmergeMe& operator=(const PmergeMe& rhs);

        /* Destructor */
        ~PmergeMe();

        /* Operators */
        bool operator==(const PmergeMe& rhs) const;

        /* Utils */
        void            printDeque(std::deque<int> to_print);
        void            printList(std::list<int> to_print);

        /* Algorithms */
        template<typename Container>
        void            mergeInsertionSort(Container& input);

        /* Setter */
        int             setDeque(int argc, char **argv);
        int             setList(int argc, char **argv);

        /* Getter */
        std::deque<int> getDeque();
        std::list<int>  getList();
        
    /* Attributes *************************************************************** */
    private:
        std::deque<int> _inputd;
        std::list<int>  _inputl;
};

#endif