/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:16:44 by root              #+#    #+#             */
/*   Updated: 2023/02/17 21:58:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes.h *************************************************************** */

#include "ft_containers.hpp"

/* Functions **************************************************************** */

template <class T>
std::string isEqual(std::stack<T>& std_stack, ft::stack<T>& ft_stack)
{
    std::stack<T> std_stack_copy = std_stack;
    ft::stack<T> ft_stack_copy = ft_stack;

    if (std_stack_copy.size() != ft_stack_copy.size())
        return ("✘");
    while (!std_stack_copy.empty() && !ft_stack_copy.empty())
    {
        if (ft_stack_copy.top() != std_stack_copy.top())
            return ("✘");
        ft_stack_copy.pop();
        std_stack_copy.pop();
    }
    return ("✔");
}

template <class T>
void    printStackAttributes(std::stack<T>& std_stack, ft::stack<T>& ft_stack)
{
    std::stack<T> std_stack_copy = std_stack;
    ft::stack<T> ft_stack_copy = ft_stack;

    if (std_stack_copy.empty())
        std::cout << "std_stack is empty!" << std::endl;
    else
    {
        std::cout << "Printing std_stack content: " << std::endl;
        while (!std_stack_copy.empty())
        {
            std::cout << std_stack_copy.top();
            std_stack_copy.pop();
            if (!std_stack_copy.empty())
                std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "End of std_stack content!" << std::endl << std::endl;
    }
    if (ft_stack_copy.empty())
        std::cout << "ft_stack is empty!" << std::endl;
    else
    {
        std::cout << "Printing ft_stack content: " << std::endl;
        while (!ft_stack_copy.empty())
        {
            std::cout << ft_stack_copy.top();
            ft_stack_copy.pop();
            if (!ft_stack_copy.empty())
                std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "End of ft_stack content!" << std::endl << std::endl;
    }
}

void    stack_constructor()
{
    std::cout << "/* Testing constructor vector */" << std::endl;
    clock_t             start_time, end_time;
            
    start_time = clock();
    std::stack<int>     std_stack;
    for (int i = 0; i < 100; i++)
        std_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;
            
    start_time = clock();
    ft::stack<int>      ft_stack;
    for (int i = 0; i < 100; i++)
        ft_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;
    std::cout << "/* Constructor vector done */" << std::endl << std::endl;
}

void    stack_operator_assignement()
{
    std::cout << "/* Testing operator= */" << std::endl;
    clock_t             start_time, end_time;

    start_time = clock();
    std::stack<int>     std_stack_1;
    std::stack<int>     std_stack_2;
    for (int i = 0; i < 100; i++)
        std_stack_1.push(i);
    std_stack_2 = std_stack_1;
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft::stack<int>      ft_stack_1;
    ft::stack<int>      ft_stack_2;
    for (int i = 0; i < 100; i++)
        ft_stack_1.push(i);
    ft_stack_2 = ft_stack_1;
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    printStackAttributes<int>(std_stack_2, ft_stack_2);
    std::cout << "Result: " << isEqual<int>(std_stack_2, ft_stack_2) << std::endl;
    std::cout << "/* Operator= done */" << std::endl << std::endl;
}

void    stack_top()
{
    std::cout << "/* Testing top */" << std::endl;
    std::stack<int>     std_stack;
    ft::stack<int>      ft_stack;
    for (int i = 0; i < 100; i++)
        std_stack.push(i);
    for (int i = 0; i < 100; i++)
        ft_stack.push(i);
    std::cout << "STD top: " << std_stack.top() << std::endl;
    std::cout << "FT top: " << ft_stack.top() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl; 
    std::cout << "/* Top done */" << std::endl << std::endl;
}

void    stack_empty()
{
    std::cout << "/* Testing empty */" << std::endl;
    clock_t             start_time, end_time;
    std::stack<int>     std_stack;
    ft::stack<int>      ft_stack;
            
    std::cout << "STD empty: " << std_stack.empty() << std::endl;
    std::cout << "FT empty: " << ft_stack.empty() << std::endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        std_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;
            
    start_time = clock();
    for (int i = 0; i < 100; i++)
        ft_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;
            
    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "STD empty: " << std_stack.empty() << std::endl;
    std::cout << "FT empty: " << ft_stack.empty() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        std_stack.pop();
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        ft_stack.pop();
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;
            
    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "STD empty: " << std_stack.empty() << std::endl;
    std::cout << "FT empty: " << ft_stack.empty() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;
    std::cout << "/* Empty done */" << std::endl << std::endl;
}

void    stack_size()
{
    std::cout << "/* Testing size */" << std::endl;
    clock_t             start_time, end_time;
    std::stack<int>     std_stack;
    ft::stack<int>      ft_stack;
            
    start_time = clock();
    for (int i = 0; i < 100; i++)
        std_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    for (int i = 0; i < 100; i++)
        ft_stack.push(i);
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;
                
    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "STD size: " << std_stack.size() << std::endl;
    std::cout << "FT size: " << ft_stack.size() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;
            
    start_time = clock();
    std_stack.pop();
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    ft_stack.pop();
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "STD size: " << std_stack.size() << std::endl;
    std::cout << "FT size: " << ft_stack.size() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;
            
    start_time = clock();
    for (int i = 0; i < 4; i++)
        std_stack.pop();
    end_time = clock();
    std::cout << "Time taken by std::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    start_time = clock();
    for (int i = 0; i < 4; i++)
        ft_stack.pop();
    end_time = clock();
    std::cout << "Time taken by ft::stack: " << (end_time - start_time) << " microseconds" << std::endl;

    printStackAttributes<int>(std_stack, ft_stack);
    std::cout << "STD size: " << std_stack.size() << std::endl;
    std::cout << "FT size: " << ft_stack.size() << std::endl;
    std::cout << "Result: " << isEqual<int>(std_stack, ft_stack) << std::endl;
    std::cout << "/* Size done */" << std::endl;
}

void    stack_relational_operators()
{
    std::cout << "/* Testing relational operators */" << std::endl;
    std::stack<int> std_stack_1;
    std::stack<int> std_stack_2;
    ft::stack<int>  ft_stack_1;
    ft::stack<int>  ft_stack_2;

    for (int i = 0; i < 10; i++)
    {
        std_stack_1.push(i);
        ft_stack_1.push(i);
    }
    std_stack_2 = std_stack_1;
    ft_stack_2 = ft_stack_1;

    std::cout << "stack1: " << std::endl;
    printStackAttributes(std_stack_1, ft_stack_1);
    std::cout << "stack2: " << std::endl;
    printStackAttributes(std_stack_2, ft_stack_2);

    std::cout << "std_stack_1 < std_stack_2 : " << (std_stack_1 < std_stack_2) << std::endl;
    std::cout << "std_stack_1 <= std_stack_2: " << (std_stack_1 <= std_stack_2) << std::endl;
    std::cout << "std_stack_1 > std_stack_2 : " << (std_stack_1 > std_stack_2) << std::endl;
    std::cout << "std_stack_1 >= std_stack_2: " << (std_stack_1 >= std_stack_2) << std::endl;
    std::cout << "std_stack_1 == std_stack_2: " << (std_stack_1 == std_stack_2) << std::endl;
    std::cout << "std_stack_1 != std_stack_2: " << (std_stack_1 != std_stack_2) << std::endl;

    std::cout << "ft_stack_1 < ft_stack_2 : " << (ft_stack_1 < ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 <= ft_stack_2: " << (ft_stack_1 <= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 > ft_stack_2 : " << (ft_stack_1 > ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 >= ft_stack_2: " << (ft_stack_1 >= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 == ft_stack_2: " << (ft_stack_1 == ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 != ft_stack_2: " << (ft_stack_1 != ft_stack_2) << std::endl;

    std_stack_1.pop();
    ft_stack_1.pop();
    std::cout << "stack1: " << std::endl;
    printStackAttributes(std_stack_1, ft_stack_1);
    std::cout << "stack2: " << std::endl;
    printStackAttributes(std_stack_2, ft_stack_2);

    std::cout << "std_stack_1 < std_stack_2 : " << (std_stack_1 < std_stack_2) << std::endl;
    std::cout << "std_stack_1 <= std_stack_2: " << (std_stack_1 <= std_stack_2) << std::endl;
    std::cout << "std_stack_1 > std_stack_2 : " << (std_stack_1 > std_stack_2) << std::endl;
    std::cout << "std_stack_1 >= std_stack_2: " << (std_stack_1 >= std_stack_2) << std::endl;
    std::cout << "std_stack_1 == std_stack_2: " << (std_stack_1 == std_stack_2) << std::endl;
    std::cout << "std_stack_1 != std_stack_2: " << (std_stack_1 != std_stack_2) << std::endl;

    std::cout << "ft_stack_1 < ft_stack_2 : " << (ft_stack_1 < ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 <= ft_stack_2: " << (ft_stack_1 <= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 > ft_stack_2 : " << (ft_stack_1 > ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 >= ft_stack_2: " << (ft_stack_1 >= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 == ft_stack_2: " << (ft_stack_1 == ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 != ft_stack_2: " << (ft_stack_1 != ft_stack_2) << std::endl;

    std_stack_1.push(10);
    std_stack_1.push(10);
    ft_stack_1.push(10);
    ft_stack_1.push(10);
    std::cout << "stack1: " << std::endl;
    printStackAttributes(std_stack_1, ft_stack_1);
    std::cout << "stack2: " << std::endl;
    printStackAttributes(std_stack_2, ft_stack_2);

    std::cout << "std_stack_1 < std_stack_2 : " << (std_stack_1 < std_stack_2) << std::endl;
    std::cout << "std_stack_1 <= std_stack_2: " << (std_stack_1 <= std_stack_2) << std::endl;
    std::cout << "std_stack_1 > std_stack_2 : " << (std_stack_1 > std_stack_2) << std::endl;
    std::cout << "std_stack_1 >= std_stack_2: " << (std_stack_1 >= std_stack_2) << std::endl;
    std::cout << "std_stack_1 == std_stack_2: " << (std_stack_1 == std_stack_2) << std::endl;
    std::cout << "std_stack_1 != std_stack_2: " << (std_stack_1 != std_stack_2) << std::endl;

    std::cout << "ft_stack_1 < ft_stack_2 : " << (ft_stack_1 < ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 <= ft_stack_2: " << (ft_stack_1 <= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 > ft_stack_2 : " << (ft_stack_1 > ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 >= ft_stack_2: " << (ft_stack_1 >= ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 == ft_stack_2: " << (ft_stack_1 == ft_stack_2) << std::endl;
    std::cout << "ft_stack_1 != ft_stack_2: " << (ft_stack_1 != ft_stack_2) << std::endl;

    std::cout << "/* Relational operators done */" << std::endl;
}
