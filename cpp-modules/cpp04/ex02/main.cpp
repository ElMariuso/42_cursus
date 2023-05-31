/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:44:38 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:12:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
    std::cout << "-- Stack Constructors ---" << std::endl;
    Cat character1;
    Dog character2;
    std::cout << "-- End of Stack Constructors ---" << std::endl;
    std::cout << std::endl;

    std::cout << "-- Make Sound ---" << std::endl;
    character1.makeSound();
    character2.makeSound();
    std::cout << "-- End of Make Sound ---" << std::endl;
    std::cout << std::endl;

    std::cout << "-- Destructors ---" << std::endl;
}

/* The Wrong main */

// int main()
// {
//     std::cout << "--- Stack Constructors ---" << std::endl;
//     Animal  heap_character1;
//     Cat     heap_character2;
//     Dog     heap_character3;
//     std::cout << "--- End of Stack Constructorss ---" << std::endl;
//     std::cout << std::endl;

//     int     size = 10;
//     Animal *animals[size];

//     std::cout << "--- Heap Constructors Array ---" << std::endl;
//     for (int i = 0; i < size; i++)
//     {
//         if (i % 2 == 0)
//             animals[i] = new Cat();
//         else
//             animals[i] = new Dog();
//     }
//     std::cout << "--- End of Heap Constructors Array ---" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Make Sound ---" << std::endl;
//     for (int i = 0; i < size; i++)
//         animals[i]->makeSound();
//     std::cout << "--- End of Make Sound ---" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Set Ideas ---" << std::endl;
//     for (int i = 0; i < size; i++)
//     {
//         animals[i]->getBrain()->setMultIdeas("I want to eat!");
//         animals[i]->getBrain()->setIdea("Maybe not...", 2);
//     }
//     std::cout << "--- End of Set Ideas ---" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Show some Ideas ---" << std::endl;
//     for (int i = 0; i < size; i++)
//     {
//         std::cout << animals[i]->getBrain()->getIdea(0) << std::endl;
//         std::cout << animals[i]->getBrain()->getIdea(1) << std::endl;
//         std::cout << animals[i]->getBrain()->getIdea(2) << std::endl;
//         std::cout << animals[i]->getBrain()->getIdea(3) << std::endl;
//     }
//     std::cout << "--- End of Show some Ideas ---" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Destructors Heap Array ---" << std::endl;
//     for (int i = 0; i < size; i++)
//     {
//         delete animals[i];
//         animals[i] = NULL;
//     }
//     std::cout << "--- End of Destructors Heap Array ---" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Other Destructors ---" << std::endl;
//     return (0);
// }