/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:13:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 13:47:57 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//constructeur
Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure Constructor Called" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	// std::cout << "Cure Copy constructor Called" << std::endl;
}

//operateur
Cure &Cure::operator=(const Cure& src)
{
	// std::cout << "Cure operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

//destructeur
Cure::~Cure()
{
	// std::cout << "Cure Destructor Called" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *"<< std::endl;
}
