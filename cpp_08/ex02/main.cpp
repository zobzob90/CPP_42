/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:08 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/02 16:47:27 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void mutantTest()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(10);

	std::cout << mstack.top() << std::endl; // top affiche le dernier donc 10
	
	mstack.pop(); // retire le dernier donc 10
	
	std::cout << mstack.size() << std::endl; // affiche 1, il ne reste que 5 dans la pile

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void listTest()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(10);

	std::cout << mstack.back() << std::endl; // top affiche le dernier donc 10
	
	mstack.pop_back(); // retire le dernier donc 10
	
	std::cout << mstack.size() << std::endl; // affiche 1, il ne reste que 5 dans la pile

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin(); 
	std::list<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

int main(void)
{
	std::cout << "Mutant Test" << std::endl;
	mutantTest();
	std::cout << std::endl;
	std::cout << "List Test" << std::endl;
	listTest();
	
	return (0);
}
