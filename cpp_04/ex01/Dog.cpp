/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:16 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:27:21 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) 
{
	std::cout << YELLOW << "🐶" << " Dog Default Constructor Called" << RESET << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type), brain(new Brain())
{
	std::cout << CYAN << "Dog Param Constructor Called for: " << YELLOW << type << RESET << std::endl; 	
}

Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) 
{
	std::cout << GREEN << "Dog Copy Constructor Called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		if (brain)
			delete brain;
		brain = new Brain(*src.brain);
		std::cout << YELLOW << "🐶" <<  " Dog Operator Called" << RESET << std::endl;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << YELLOW << "💩" <<  " Dog Destructor Called" << RESET << std::endl;
	delete brain;
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

void	Dog::setIdea(int index, const std::string& idea)
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

std::string	Dog::getIdea(int index) const
{
	std::cout << "🧠" << WHITE << "Idea at index:" << RED << index << RESET << std::endl;
	if (index < 0 || index >= 100)
	{
		std::cout << "🧠" << WHITE << " Invalid number of ideas" << RESET << std::endl;
		return "";
	}
	return brain->getIdea(index);
}
