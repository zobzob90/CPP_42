/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 18:33:02 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << YELLOW << "🐱" << " Cat Default Constructor Called" << RESET << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << CYAN << "Cat Param Constructor Called for: " << YELLOW << type << RESET << std::endl; 	
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << GREEN << "Cat Copy Constructor Called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		std::cout << YELLOW << "😼" <<  " Cat Operator Called" << RESET << std::endl;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << YELLOW << "🙀" <<  " Cat Destructor Called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << WHITE << "Cat say " << RED << "Meow Meow" << WHITE << " Bitch" << RESET << std::endl;
}

std::string Cat::getType() const
{
	std::cout << WHITE << "The animal is a " << RED << type << RESET << std::endl;
	return (type);
}
