/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:30 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 18:45:05 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << "🐱" << " WrongCat Default Constructor Called" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
	std::cout << CYAN << "WrongCat Param Constructor Called for: " << YELLOW << type << RESET << std::endl; 	
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << GREEN << "WrongCat Copy Constructor Called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
	{
		WrongAnimal::operator=(src);
		std::cout << YELLOW << "😼" <<  " WrongCat Operator Called" << RESET << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "🙀" <<  " WrongCat Destructor Called" << RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << WHITE << "WrongCat say " << RED << "HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << RESET << std::endl;
}

std::string WrongCat::getType() const
{
	std::cout << WHITE << "The Animal is a " << RED << type << RESET << std::endl;
	return (type);
}
