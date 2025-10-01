/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:03:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/01 15:46:20 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> container;

	for (int i = 0; i < 5; ++i)
		container.push_back(i * 10);
	
	try 
	{
		std::cout << "TEST 1 : Find a Value at the beginning" << std::endl;
		std::vector<int>::const_iterator it = easyfind(container, 0);
		std::cout << "Value found : " << *it << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	try 
	{
		std::cout << "TEST 2 : Find a Value at the middle" << std::endl;
		std::vector<int>::const_iterator it = easyfind(container, 20);
		std::cout << "Value found : " << *it << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "TEST 3 : Find a Value at the end" << std::endl;
		std::vector<int>::const_iterator it = easyfind(container, 40);
		std::cout << "Value found : " << *it << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "TEST 4 : Find a Value that dont exist" << std::endl;
		std::vector<int>::const_iterator it = easyfind(container, -90);
		std::cout << "Value found : " << *it << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return (0);
}
