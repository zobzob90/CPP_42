/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:46:28 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/16 14:05:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void basicTest()
{
	std::cout << "	==== BASIC TEST ====" << std::endl;
	try
	{
		Span _span = Span(5);

		_span.addNumber(6);
		_span.addNumber(3);
		_span.addNumber(17);
		_span.addNumber(9);
		_span.addNumber(11);
		std::cout << "List is : " << _span << std::endl;
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
	std::cout << "	==== NEGATIVE TEST ====" << std::endl;
	try
	{
			Span _span = Span(5);
	
		_span.addNumber(6);
		_span.addNumber(-3);
		_span.addNumber(17);
		_span.addNumber(9);
		_span.addNumber(11);
		
		std::cout << "List is : " << _span << std::endl;
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
	for (int i = 0; i < 10000; i++)
		v.push_back(std::rand());
	Span _span(10000);
	
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

void	errorTest()
{
	std::cout << "	=== Error Test ===" << std::endl;
	try
	{
		Span _span = Span(1);
		_span.addNumber(0);
		std::cout << "List is : " << _span << std::endl;
		std::cout << "Shortest Span is : " << _span.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << _span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	errorTest2()
{
	std::cout << "	=== Error Test2 : Too Many Numbers===" << std::endl;
	try
	{
		Span _span = Span(1);
		_span.addNumber(0);
		_span.addNumber(1);
		std::cout << "List is : " << _span << std::endl;
		std::cout << "Shortest Span is : " << _span.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << _span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	basicTest();
	negatifTest();
	largeTest();
	errorTest();
	errorTest2();
	return (0);
}