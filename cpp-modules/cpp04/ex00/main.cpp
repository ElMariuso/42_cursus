/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:44:38 by root              #+#    #+#             */
/*   Updated: 2022/10/20 19:53:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Stack Constructors ---" << std::endl;
    Animal      character1;
    Dog         character2;
    Cat         character3;
    WrongAnimal character4;
    WrongCat    character5;
    std::cout << std::endl;

    std::cout << "--- Heap Constructors ---" << std::endl;
    Animal*         character6 = new Animal();
    Dog*            character7 = new Dog();
    Cat*            character8 = new Cat();
    WrongAnimal*    character9 = new WrongAnimal();
    WrongAnimal*    character10 = new WrongCat();
    WrongCat*       character11 = new WrongCat();
    std::cout << std::endl;

    std::cout << "--- Stack Make Sound ---" << std::endl;
    character1.makeSound();
    character2.makeSound();
    character3.makeSound();
    character4.makeSound();
    character5.makeSound();
    std::cout << std::endl;

    std::cout << "--- Heap Make Sound ---" << std::endl;
    character6->makeSound();
    character7->makeSound();
    character8->makeSound();
    character9->makeSound();
    character10->makeSound();
    character11->makeSound();
    std::cout << std::endl;

    std::cout << "--- Heap Destructors ---" << std::endl;
    delete character6;
    delete character7;
    delete character8;
    delete character9;
    delete character10;
    delete character11;
    std::cout << std::endl;

    std::cout << "--- Stack Destructors ---" << std::endl;
}