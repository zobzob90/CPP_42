/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:16 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 18:33:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << YELLOW << "🐶" << " Dog Default Constructor Called" << RESET << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << CYAN << "Dog Param Constructor Called for: " << YELLOW << type << RESET << std::endl; 	
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << GREEN << "Dog Copy Constructor Called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		std::cout << YELLOW << "🐶" <<  " Dog Operator Called" << RESET << std::endl;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << YELLOW << "💩" <<  " Dog Destructor Called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << WHITE << "Dog says " << RED << "Woof Woof!" << RESET << std::endl;
}

std::string Dog::getType() const
{
	std::cout << WHITE << "The animal is a " << RED << type << RESET << std::endl;
	return (type);
}
