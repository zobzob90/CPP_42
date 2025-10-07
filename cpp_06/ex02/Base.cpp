/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:10:02 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/06 13:25:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// genere une classe random 
Base* generate(void)
{
	static bool first_call = true;
	
	if (first_call)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		first_call = false;	
	}
	
	int	r = std::rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

// identifie le type via un pointeur
// dynamic_cast permet de tester le type reel en securite
void	identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "NULL POINTER" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" <<  std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow" << std::endl;
}

// permet d'identifier via l'adresse - lance une execption si echec
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(...) {}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(...) {}

	std::cout << "Unknown" << std::endl;
}
