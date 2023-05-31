/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:41:16 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/04 10:41:18 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
    this->max_index = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void    PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->contact[this->index].set_index(this->index + 1);
    this->contact[this->index].set_infos(first_name, last_name, nickname, phone_number, darkest_secret);
    this->index++;
    this->max_index++;
    if (this->index >= 8)
        this->index = 0;
    if (this->max_index >= 8)
        this->max_index = 8;
}

void    PhoneBook::search_contact(char ci) const
{
    int index;

    index = ci - 48;
    this->contact[index - 1].display_infos();
}

void    PhoneBook::display_contacts() const
{
    std::cout << std::setw(10);
    std::cout << "Index" << "|";
    std::cout << std::setw(10);
    std::cout << "First Name" << "|";
    std::cout << std::setw(10);
    std::cout << "Last Name" << "|";
    std::cout << std::setw(10);
    std::cout << "Nickname" << std::endl;
    for (int i = 0; i != this->max_index; i++)
        this->contact[i].alt_display_infos();
}