/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:51:11 by mthiry            #+#    #+#             */
/*   Updated: 2022/10/25 18:42:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{ }

/* Other functions */

Base*   generate(void)
{
    Base*   ret = NULL;
    int     i;

    std::srand((unsigned)time(NULL) + std::rand());
    i = rand() % 3;
    switch (i)
    {
        case 0:
            ret = new A;
            break ;
        case 1:
            ret = new B;
            break ;
        case 2:
            ret = new C;
            break ;
        default:
            std::cerr << "Error random" << std::endl;
            break ;
    }
    return (ret);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is type A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "This is type B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "This is type C" << std::endl;
}

void    identify(Base& p)
{
    try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This is of type A" << std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This is of type B" << std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This is of type C" << std::endl;
	}
	catch(std::exception& e)
	{
	}
}