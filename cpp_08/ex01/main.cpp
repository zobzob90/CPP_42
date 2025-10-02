/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:46:28 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/02 14:03:43 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void basicTest()
{
	Span _span = Span(5);

	_span.addNumber(6);
	_span.addNumber(3);
	_span.addNumber(17);
	_span.addNumber(9);
	_span.addNumber(11);

	std::cout << "	==== BASIC TEST ====" << std::endl;
	std::cout << "List is : " << _span << std::endl;
	
	try
	{
		std::cout << "Shortest Span is : " << _span.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << _span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
	
	std::cout << std::endl;
}


void negatifTest()
{
	Span _span = Span(5);
	
	_span.addNumber(6);
	_span.addNumber(-3);
	_span.addNumber(17);
	_span.addNumber(9);
	_span.addNumber(11);

	std::cout << "	==== NEGATIVE TEST ====" << std::endl;
	std::cout << "List is : " << _span << std::endl;
	try
	{
		std::cout << "Shortest Span is : " << _span.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << _span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
	std::cout << std::endl;
}

void largeTest()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(std::rand());
	Span _span(10);
	
	try
	{
		_span.addNumber(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " <<  e.what() << '\n';
	}
	
	std::cout << "	==== LARGE TEST ====" << std::endl;
	std::cout << "List is : " << _span << std::endl;
	try
	{
		std::cout << "Shortest Span is : " << _span.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << _span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}

int main(void)
{
	basicTest();
	negatifTest();
	largeTest();
	return (0);
}