/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:41:44 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 14:22:08 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	// std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._templates[i])
			_templates[i] = src._templates[i]->clone(); // Deep Copy ici
		else
			_templates[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& src)
{
	// std::cout << "MateriaSource Operator Called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
				delete _templates[i];
			if (src._templates[i])
				_templates[i] = src._templates[i]->clone(); // Deep Copy here too
			else
				_templates[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			// std::cout << "MateriaSource learned" << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
		{
			// std::cout << "MateriaSource created !" << std::endl;
			return _templates[i]->clone();
		}
	}	
	std::cout << "MateriaSource doesnt know !" << std::endl;
	return NULL;
}
