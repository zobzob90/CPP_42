/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:47 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 15:10:53 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Color.hpp"

Character::Character() : _name("Unknown")
{
	// std::cout << "Character Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_unequiped[i] = NULL;
	}
}

Character::Character(const std::string& name) : _name(name)
{
	// std::cout << "Character Param Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_unequiped[i] = NULL;
	}
}

Character::Character(const Character& src)
{
	// std::cout << "Character Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone(); // deep copy
		else if (src._unequiped[i])
			_unequiped[i] = src._unequiped[i]->clone();
		else
		{
			_inventory[i] = NULL;
			_unequiped[i] = NULL;	
		}
	}
}

Character &Character::operator=(const Character &src)
{
	// std::cout << "Character Operator Called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
            if (_inventory[i])
				delete _inventory[i];
			if (_unequiped[i])
				delete _unequiped[i];
            if (src._inventory[i])
                _inventory[i] = src._inventory[i]->clone(); // ✅ Deep copy
            else
                _inventory[i] = NULL;
                
			if (src._unequiped[i])
				_unequiped[i] = src._unequiped[i]->clone(); // ✅ Deep copy
			else
				_unequiped[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (_unequiped[i])
			delete _unequiped[i];
	}
}

bool Character::fullInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
			return (false);	
	}
	return (true);
}

const std::string& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << _name << " has no materia to equip." << std::endl;
		return ;	
	}
	if (fullInventory())
	{
		std::cout << _name << " has a full inventory !" << std::endl;
		delete m;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << RED << _name << RESET << " equipped " << m->getType() << " at slot " << YELLOW << i << RESET << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << _name << " invalid slot index !" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << _name << " slot " << idx << " is already empty !" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_unequiped[i])
		{
			_unequiped[i] = _inventory[idx];
			_inventory[idx] = NULL;
			std::cout << _name << " unequipped materia from slot " << idx << std::endl;
			return ;
		}
	}
	std::cout << _name << " unequipped storage full, deleting materia from slot " << idx << std::endl;
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << _name << " invalid slot index ! " << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << _name << " slot " << idx << " is empty nothing to use !" << std::endl;
		return ;
	}
	if (_inventory[idx]->getType() == "ice")
		std::cout << RED << _name << RESET << " 🧊 shoots an ice bolt at " << target.getName() << std::endl;
	else if (_inventory[idx]->getType() == "cure")
		std::cout << RED << _name << RESET << " ❤️‍🩹 heals " << target.getName() << "'s wounds" << std::endl;
	else if (_inventory[idx]->getType() == "fire")
		std::cout << RED <<  _name << RESET << " 🔥 shoots a fire ball at " << target.getName() << std::endl;
	else if (_inventory[idx]->getType() == "prison")
		std::cout << RED << _name  << RESET << " 🧱 uses 18 months of suspended sentence on " << target.getName() << std::endl;
	else
		_inventory[idx]->use(target); // Fallback to default materia message
}
