/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:15:58 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:02:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    this->setMultIdeas("I have nothing in my brain!");
    std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
    *this = rhs;
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::Brain(const Brain* rhs)
{
    *this = rhs;
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called!" << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs)
{
    for (int i = 0; i != 100; i++)
        this->setIdea(rhs.getIdea(i), i);   
    return (*this);
}

/* Functions */

void    Brain::setMultIdeas(std::string idea)
{
    for (int i = 0; i != 100; i++)
        this->_ideas[i] = idea;
}

void    Brain::setIdea(std::string idea, int i)
{
    this->_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    return (this->_ideas[i]);
}