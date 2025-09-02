/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:39:41 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 14:02:23 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() // Constructeur
{
	std::cout << "🧠" << RED << " Brain Default Constructor Called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "🧠 I got no ideas";
}

Brain::Brain(const Brain& src) // Constructeur de Copie
{
	std::cout << "🧠" << RED << " Brain Copy Constructor Called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(const Brain& src) // operateur de surcharge
{
	std::cout << "🧠" << RED << " Brain Param Constructor Called" << RESET << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain() // Destructeur
{
	std::cout << "🧠" << YELLOW << " Brain Destructor Called" << RESET << std::endl;
}

void	Brain::setIdea(int index, const std::string& idea)
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
	ideas[index] = idea;
	std::cout << "🧠" << WHITE << " Idea set at Index" << RESET << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	std::cout << "🧠" << WHITE << "Idea at index:" << RED << index << RESET << std::endl;
	if (index < 0 || index >= 100)
	{
		std::cout << "🧠" << WHITE << " Invalid number of ideas" << RESET << std::endl;
		return "";
	}
	return (ideas[index]);
}
