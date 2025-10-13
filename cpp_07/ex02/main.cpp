/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:16:37 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/13 13:43:24 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "Test de valeur" << std::endl;
	std::cout << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << ", " << numbers[4] << std::endl;
	std::cout << mirror[0] << ", " << mirror[1] << ", " << mirror[2] << ", " << mirror[4] << std::endl;
	std::cout << std::endl;
	
	Array<int> def; // test pour constructeur par defaut
	Array<int>defInit(5);
	std::cout << "Test taille constructeur par defaut : " << "size " << def.size() << std::endl; // test taille
	std::cout << std::endl;
	std::cout << "Test avec un constructeur par default a 5 ->" << " "; // test valeur par defaut
	for(unsigned int i = 0; i < defInit.size(); i++)
		std::cout << defInit[i] << " ";
	std::cout << std::endl;
	
	int	*a = new int();
	int *b = new int(2);
	std::cout << "Test constructeur avec init : " << *a << std::endl; // <- creer une initialisation par default
	std::cout << "Test constructeur avec init : " << *b << std::endl; // <- creer une initialisation a 2
	std::cout << std::endl;
	
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	
	for (int i = 0; i < MAX_VAL; i++) // test deep copy
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try 
	{
		std::cout << "Test accès avec tableau vide :" << std::endl;
		def[0] = 42;
	} 
	catch(const std::exception& e) 
	{
    	std::cerr << "❌ Exception sur tableau vide: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Test accès avec index négatif (-2)..." << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "❌ Exception index négatif: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Test accès hors limites (index " << MAX_VAL << ")..." << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "❌ Exception index trop grand: " << e.what() << std::endl;
	}

	delete [] mirror;
	delete a;
	delete b;
	return (0);
}
