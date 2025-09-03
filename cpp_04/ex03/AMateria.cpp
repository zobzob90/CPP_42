/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:50 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/03 14:21:44 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructeur
AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "Constructor AMateria Called" << std::endl;
}

// Constructeur de copie
AMateria::AMateria(const AMateria& src)
{
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = src;
}

// Operateur d'affectation
AMateria &AMateria::operator=(const AMateria& src)
{
	std::cout << "AMateria Operator Constructor Called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// Destructeur
AMateria::~AMateria()
{
	std::cout << "Destructor Amateria Called" << std::endl;
}

// Getter
std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses" << this->_type << " on " << target.getName() << " *" << std::endl;
}
