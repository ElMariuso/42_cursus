/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:59:16 by root              #+#    #+#             */
/*   Updated: 2022/10/26 20:46:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		Span	span1(5);

		try
		{
			span1.addNumber(5);
			span1.addNumber(9);
			span1.addNumber(156);
			span1.addNumber(-25);
			span1.addNumber(89);
			span1.addNumber(38);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << "Max span is " << span1.longestSpan() << "." << std::endl;
		std::cout << "Min span is " << span1.shortestSpan() << "." << std::endl;
	}
	std::cout << std::endl;
	{
		Span					span2(10000);
		std::vector<int>		vect;

		try
		{
			for (int i = 0; i < 10001; i++)
				vect.push_back(i);
			span2.addNumber(vect.begin(), vect.end());
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << "Max span is " << span2.longestSpan() << "." << std::endl;
		std::cout << "Min span is " << span2.shortestSpan() << "." << std::endl;

	}

	return 0;
}

// int main()
// {
//     Span sp = Span(5);
    
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
// }