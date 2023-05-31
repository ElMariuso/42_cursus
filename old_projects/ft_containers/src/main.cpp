/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:49:05 by root              #+#    #+#             */
/*   Updated: 2023/02/17 22:57:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes ***************************************************************** */

#include <iostream>
#include "ft_containers.hpp"

/* Functions **************************************************************** */

void vector_tester()
{
    std::string command = "";
    
    std::cout << "Welcome to vector tester !" << std::endl \
    << "[BASIC COMMANDS]: " << std::endl \
    << "HELP: Redisplay this" << std::endl \
    << "TESTS: Display all tests with their index" << std::endl \
    << "ALL : Launch all tests" << std::endl \
    << "EXIT: Return at home" << std::endl;
    while (1)
    {
        std::cout << "Enter a command or an index for the test: ";
        std::getline(std::cin, command);
        if (command == "HELP")
        {
            std::cout << "[BASIC COMMANDS]: " << std::endl \
            << "HELP: Redisplay this" << std::endl \
            << "TESTS: Display all tests with their index" << std::endl \
            << "ALL : Launch all tests" << std::endl \
            << "EXIT: Return at home" << std::endl;
        }
        else if (command == "TESTS")
        {
            std::cout << "[TESTS WITH INDEX]: " << std::endl \
            << "1: constructor" << std::endl \
            << "2: constructor with value" << std::endl \
            << "3: constructor with iterator" << std::endl \
            << "4: copy constructor" << std::endl \
            << "5: operator=" << std::endl \
            << "6: assign by range" << std::endl \
            << "7: assign by value" << std::endl \
            << "8: at operator" << std::endl \
            << "9: operator[]" << std::endl \
            << "10: vector.front()" << std::endl \
            << "11: vector.back()" << std::endl \
            << "12: vector.rbegin()" << std::endl \
            << "13: vector.rend()" << std::endl \
            << "14: vector.empty()" << std::endl \
            << "15: vector.size()" << std::endl \
            << "16: vector.capacity()" << std::endl \
            << "17: vector.clear()" << std::endl \
            << "18: insert mono value" << std::endl \
            << "19: insert multi values" << std::endl \
            << "20: insert range of values" << std::endl \
            << "21: erase" << std::endl \
            << "22: erase range of values" << std::endl \
            << "23: vector.push_back()" << std::endl \
            << "24: vector.pop_back()" << std::endl \
            << "25: vector.resize()" << std::endl \
            << "26: vector.swap()" << std::endl \
            << "27: relational operators" << std::endl;
        }
        else if (command == "ALL")
        {
            vector_constructor();
            vector_constructor_value(); 
            vector_constructor_iterator();
            vector_copy_constructor();
            vector_operator_assignement();
            vector_assign_range();
            vector_assign_value();
            vector_at();
            vector_operator_brackets();
            vector_front();
            vector_back();
            vector_rbegin();
            vector_rend();
            vector_empty();
            vector_size();
            vector_capacity();
            vector_clear();
            vector_insert_mono();
            vector_insert_multi();
            vector_insert_range();
            vector_erase();
            vector_erase_range();
            vector_push_back();
            vector_pop_back();
            vector_resize();
            vector_swap();
            vector_relational_operators();
        }
        else if (command == "1")
            vector_constructor();
        else if (command == "2")
            vector_constructor_value();
        else if (command == "3")
            vector_constructor_iterator();
        else if (command == "4")
            vector_copy_constructor();
        else if (command == "5")
            vector_operator_assignement();
        else if (command == "6")
            vector_assign_range();
        else if (command == "7")
            vector_assign_value();
        else if (command == "8")
            vector_at();
        else if (command == "9")
            vector_operator_brackets();
        else if (command == "10")
            vector_front();
        else if (command == "11")
            vector_back();
        else if (command == "12")
            vector_rbegin();
        else if (command == "13")
            vector_rend();
        else if (command == "14")
            vector_empty();
        else if (command == "15")
            vector_size();
        else if (command == "16")
            vector_capacity();
        else if (command == "17")
            vector_clear();
        else if (command == "18")
            vector_insert_mono();
        else if (command == "19")
            vector_insert_multi();
        else if (command == "20")
            vector_insert_range();
        else if (command == "21")
            vector_erase();
        else if (command == "22")
            vector_erase_range();
        else if (command == "23")
            vector_push_back();
        else if (command == "24")
            vector_pop_back();
        else if (command == "25")
            vector_resize();
        else if (command == "26")
            vector_swap();
        else if (command == "27")
            vector_relational_operators();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "[ERROR]: Command unknown, please try again" << std::endl;
    }
}

void stack_tester()
{
    std::string command = "";
    
    std::cout << "Welcome to stack tester !" << std::endl \
    << "[BASIC COMMANDS]: " << std::endl \
    << "HELP: Redisplay this" << std::endl \
    << "TESTS: Display all tests with their index" << std::endl \
    << "ALL : Launch all tests" << std::endl \
    << "EXIT: Return at home" << std::endl;
    while (1)
    {
        std::cout << "Enter a command or an index for the test: ";
        std::getline(std::cin, command);
        if (command == "HELP")
        {
            std::cout << "[BASIC COMMANDS]: " << std::endl \
            << "HELP: Redisplay this" << std::endl \
            << "TESTS: Display all tests with their index" << std::endl \
            << "ALL : Launch all tests" << std::endl \
            << "EXIT: Return at home" << std::endl;
        }
        else if (command == "TESTS")
        {
            std::cout << "[TESTS WITH INDEX]: " << std::endl \
            << "1: constructor" << std::endl \
            << "2: operator=" << std::endl \
            << "3: stack.top()" << std::endl \
            << "4: stack.empty()" << std::endl \
            << "5: stack.size()" << std::endl \
            << "6: relational operators" << std::endl;
        }
        else if (command == "ALL")
        {
            stack_constructor();
            stack_operator_assignement();
            stack_top();
            stack_empty();
            stack_size();
            stack_relational_operators();
        }
        else if (command == "1")
            stack_constructor();
        else if (command == "2")
            stack_operator_assignement();
        else if (command == "3")
            stack_top();
        else if (command == "4")
            stack_empty();
        else if (command == "5")
            stack_size();
        else if (command == "6")
            stack_relational_operators();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "[ERROR]: Command unknown, please try again" << std::endl;
    }
}

void map_tester()
{
    std::string command = "";
    
    std::cout << "Welcome to map tester !" << std::endl \
    << "[BASIC COMMANDS]: " << std::endl \
    << "HELP: Redisplay this" << std::endl \
    << "TESTS: Display all tests with their index" << std::endl \
    << "ALL : Launch all tests" << std::endl \
    << "EXIT: Return at home" << std::endl;
    while (1)
    {
        std::cout << "Enter a command or an index for the test: ";
        std::getline(std::cin, command);
        if (command == "HELP")
        {
            std::cout << "[BASIC COMMANDS]: " << std::endl \
            << "HELP: Redisplay this" << std::endl \
            << "TESTS: Display all tests with their index" << std::endl \
            << "ALL : Launch all tests" << std::endl \
            << "EXIT: Return at home" << std::endl;
        }
        else if (command == "TESTS")
        {
            std::cout << "[TESTS WITH INDEX]: " << std::endl \
            << "1: constructor" << std::endl;
        }
        else if (command == "ALL")
        {
            map_constructor();
        }
        else if (command == "1")
            map_constructor();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "[ERROR]: Command unknown, please try again" << std::endl;
    }
}

int main()
{
    std::string command = "";

    std::cout << "Welcome to ft_containers tester !" << std::endl \
    << "[BASIC COMMANDS]: " << std::endl \
    << "HELP: Redisplay this" << std::endl \
    << "VECTOR: Enter in the vector tests" << std::endl \
    << "STACK: Enter in the stack tests" << std::endl \
    << "MAP: Enter in the map tests" << std::endl \
    << "EXIT: Quit the program" << std::endl;
    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "HELP")
        {
            std::cout << "[BASIC COMMANDS]: " << std::endl \
            << "HELP: Redisplay this" << std::endl \
            << "VECTOR: Enter in the vector tests" << std::endl \
            << "STACK: Enter in the stack tests" << std::endl \
            << "MAP: Enter in the map tests" << std::endl \
            << "EXIT: Quit the program" << std::endl;
        }
        else if (command == "VECTOR")
            vector_tester();
        else if (command == "STACK")
            stack_tester();
        else if (command == "MAP")
            map_tester();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "[ERROR]: Command unknown, please try again" << std::endl;
    }
}