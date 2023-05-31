/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:40:54 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/04 10:40:57 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    this->is_empty = true;
    return ;
}

Contact::~Contact()
{
    return ;
}

void    Contact::set_index(int index)
{
    this->index = index;
}

void    Contact::set_infos(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->is_empty = false;
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

void    Contact::display_infos() const
{
    if (this->is_empty != true)
    {
        std::cout << "First name: " << this->first_name << std::endl;
        std::cout << "Last name: "  << this->last_name << std::endl;
        std::cout << "Nickname: " << this->nickname << std::endl;
        std::cout << "Phone Number: " << this->phone_number << std::endl;
        std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
    }
    else
        std::cout << "Nothing to see here, this index is empty" << std::endl;
}

void    Contact::alt_display_infos() const
{
    if (this->is_empty != true)
    {
        std::cout << std::setw(10);
        std::cout << this->index << "|";
        if (this->first_name.length() > 10)
            std::cout << this->first_name.substr(0, 9) << "." << "|";
        else
        {
            std::cout << std::setw(10);
            std::cout << this->first_name << "|";
        }
        if (this->last_name.length() > 10)
            std::cout << this->last_name.substr(0, 9) << "." << "|";
        else
        {
            std::cout << std::setw(10);
            std::cout << this->last_name << "|";
        }
        if (this->nickname.length() > 10)
            std::cout << this->nickname.substr(0, 9) << ".";
        else
        {
            std::cout << std::setw(10);
            std::cout << this->nickname;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Nothing to see here, this user is empty" << std::endl;
}