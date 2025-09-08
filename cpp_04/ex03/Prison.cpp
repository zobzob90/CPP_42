/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prison.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:33:28 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 14:51:15 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Prison.hpp"

//constructeur
Prison::Prison() : AMateria("prison")
{
	// std::cout << "Prison Constructor Called" << std::endl;
}

Prison::Prison(const Prison& src) : AMateria(src)
{
	// std::cout << "Prison Copy constructor Called" << std::endl;
}

//operateur
Prison &Prison::operator=(const Prison& src)
{
	// std::cout << "Prison operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

//destructeur
Prison::~Prison()
{
	// std::cout << "Prison Destructor Called" << std::endl;
}

AMateria* Prison::clone() const
{
	return new Prison(*this);
}

void Prison::use(ICharacter& target)
{
	std::cout << "* use 18 months of suspended sentence at" << target.getName() << " *" << std::endl;
}