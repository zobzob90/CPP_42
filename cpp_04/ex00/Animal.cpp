/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:06 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 17:48:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << RED << "🔴" << " Animal Default Constructor Called" << RESET << std::endl;
}
Animal::Animal(const std::string& type) : type(type)
{
	std::cout << CYAN << "Animal Param Constructor Called for :" << YELLOW << type << RESET << std::endl; 	
}

Animal::Animal(const Animal& src) : type(src.type)
{
	std::cout << GREEN << "Animal Copy Constructor Called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal& src)
{
	if (this != &src)
	{
		type = src.type;
		std::cout << YELLOW << "Animal Operator Called" << RESET << std::endl;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << ORANGE << "Animal Destructor Called" << RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "An animal is delivering a sound" << RESET << std::endl;
}

std::string Animal::getType() const
{
	std::cout << WHITE << "The type is this: " << RED << type << RESET << std::endl;
	return (type);
}
