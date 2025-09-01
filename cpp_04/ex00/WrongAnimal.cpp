/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:24 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 18:48:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << RED << "🔴" << " WrongAnimal Default Constructor Called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << CYAN << "Wrong Animal Param Constructor Called for :" << YELLOW << type << RESET << std::endl; 	
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type)
{
	std::cout << GREEN << "Wrong Animal Copy Constructor Called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
	{
		type = src.type;
		std::cout << YELLOW << "Wrong Animal Operator Called" << RESET << std::endl;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ORANGE << "WrongAnimal Destructor Called" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << BLUE << "A Weird Animal is screaming" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	std::cout << WHITE << "The type is this: " << RED << type << RESET << std::endl;
	return (type);
}
