/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:47 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/03 18:35:04 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unknown")
{
	std::cout << "Character Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	std::cout << "Character Param Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	std::cout << "Character Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone(); // deep copy
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character Operator Called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i];
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);	
}

Character::~Character()
{
	std::cout << "Character Destructor Called" << std::endl;
}

