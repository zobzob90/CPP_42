/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 12:42:34 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) 
{
	std::cout << YELLOW << "🐱" << " Cat Default Constructor Called" << RESET << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type),  brain(new Brain()) 
{
	std::cout << CYAN << "Cat Param Constructor Called for: " << YELLOW << type << RESET << std::endl; 	
}

Cat::Cat(const Cat& src) : Animal(src), brain(new Brain(*src.brain)) 
{
	std::cout << GREEN << "Cat Copy Constructor Called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		if (brain)
			delete brain;
		brain = new Brain(*src.brain);
		std::cout << YELLOW << "😼" <<  " Cat Operator Called" << RESET << std::endl;
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << YELLOW << "🙀" <<  " Cat Destructor Called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << WHITE << "Cat say " << RED << "Meow Meow" << RESET << std::endl;
}

std::string Cat::getType() const
{
	std::cout << WHITE << "The animal is a " << RED << type << RESET << std::endl;
	return (type);
}

void	Cat::setIdea(int index, const std::string& idea)
{
	if (idea.empty())
	{
		std::cout << "🧠" << WHITE << " I'm dumb and empty !" << RESET << std::endl;
		return ;
	}
	if (index < 0 || index >= 100)
	{
		std::cout << "🧠" << WHITE << " Invalid number of ideas" << RESET << std::endl;
		return ;
	}
	brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	std::cout << "🧠" << WHITE << "Idea at index:" << RED << index << RESET << std::endl;
	if (index < 0 || index >= 100)
	{
		std::cout << "🧠" << WHITE << " Invalid number of ideas" << RESET << std::endl;
		return "";
	}
	return brain->getIdea(index);
}
