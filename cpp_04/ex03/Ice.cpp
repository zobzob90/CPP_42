/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:38:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 15:05:21 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//constructeur
Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice Constructor Called" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	// std::cout << "Ice Copy constructor Called" << std::endl;
}

//operateur
Ice &Ice::operator=(const Ice& src)
{
	// std::cout << "Ice operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

//destructeur
Ice::~Ice()
{
	// std::cout << "Ice Destructor Called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* 🧊 shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
