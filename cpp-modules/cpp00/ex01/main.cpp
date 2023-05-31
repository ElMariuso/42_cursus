/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:41:06 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/04 10:41:09 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook   book;
    std::string command = "";
    std::string first_name = "";
    std::string last_name = "";
    std::string nickname = "";
    std::string phone_number = "";
    std::string darkest_secret = "";
    std::string index = "";

    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline (std::cin, command);
        if (command == "ADD")
        {
            std::cout << "Enter the first name: ";
            std::getline(std::cin, first_name);
            std::cout << "Enter the last name: ";
            std::getline(std::cin, last_name);
            std::cout << "Enter the nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter the phone number: ";
            std::getline(std::cin, phone_number);
            std::cout << "Enter the darkest secret: ";
            std::getline(std::cin, darkest_secret);
            book.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
        }
        else if (command == "SEARCH")
        {
            book.display_contacts();
            while (1)
            {
                std::cout << "Enter the index of the contact, type CANCEL for exit: ";
                std::getline(std::cin, index);
                if (index == "1" || index == "2"
                    || index == "3" || index == "4"
                    || index == "5" || index == "6"
                    || index == "7" || index == "8")
                {
                    book.search_contact(index[0]);
                    break ;
                }
                else if (index == "CANCEL")
                    break ;
                else
                    std::cout << "[ERROR]: Invalid index, please try again" << std::endl;
            }
        }
        else if (command == "EXIT")
            break ;
        else
            std::cout << "[ERROR]: Command unknown, please try again" << std::endl;
    }
}