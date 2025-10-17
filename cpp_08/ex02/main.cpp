/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:08 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/16 15:35:21 by ertrigna         ###   ########.fr       */
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

void reverseTest()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(10);
	mstack.push(3);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iteration normale (begin->end) : " << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Iteration inverse (end->begin) : " << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void listTest()
{
	std::list<int> mslist;

	mslist.push_back(5);
	mslist.push_back(10);

	std::cout << mslist.back() << std::endl; // top affiche le dernier donc 10
	
	mslist.pop_back(); // retire le dernier donc 10
	
	std::cout << mslist.size() << std::endl; // affiche 1, il ne reste que 5 dans la pile

	mslist.push_back(3);
	mslist.push_back(5);
	mslist.push_back(737);
	mslist.push_back(0);

	std::list<int>::iterator it = mslist.begin(); 
	std::list<int>::iterator ite = mslist.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mslist);
}

int main(void)
{
	std::cout << "Mutant Test" << std::endl;
	mutantTest();
	std::cout << std::endl;
	std::cout << "List Test" << std::endl;
	listTest();
	std::cout << std::endl;
	std::cout << "Pour le fun" << std::endl;
	reverseTest();
	
	return (0);
}
