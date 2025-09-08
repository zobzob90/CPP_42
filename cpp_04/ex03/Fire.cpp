/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:01:26 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 15:05:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

//constructeur
Fire::Fire() : AMateria("fire")
{
	// std::cout << "Fire Constructor Called" << std::endl;
}

Fire::Fire(const Fire& src) : AMateria(src)
{
	// std::cout << "Fire Copy constructor Called" << std::endl;
}

//operateur
Fire &Fire::operator=(const Fire& src)
{
	// std::cout << "Fire operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

//destructeur
Fire::~Fire()
{
	// std::cout << "Fire Destructor Called" << std::endl;
}

AMateria* Fire::clone() const
{
	return new Fire(*this);
}

void Fire::use(ICharacter& target)
{
	std::cout << "* 🔥 shoot an fire ball at " << target.getName() << " *" << std::endl;
}
