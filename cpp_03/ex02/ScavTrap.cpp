/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:54:41 by eric              #+#    #+#             */
/*   Updated: 2025/08/29 15:06:08 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap()
{
	std::cout << "🔨" << GREEN << " ScavTrap default constructor called" << RESET << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string Name) : ClapTrap(Name)
{
	std::cout << "🤖" << RED << " ScavTrap is initialized" << RESET << std::endl;
	this->hitPoints = 100;
	this->attackDamage = 20;
	this->energyPoints = 50;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "🦾" << GREY << " ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "🔀" << CYAN << " ScavTrap assignement operator sent" << RESET << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "💣" << YELLOW << " SCAVTRAP DESTRUCTOR CALLED" << RESET << std::endl; 
}

void	ScavTrap::guardGate()
{
	std::cout << RED << this->Name  << " is in Guard Mode" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "🤺" << RED << " [ATTACK]" << RESET << std::endl;
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << GREY << "ScavTrap " << this->Name << " can't attack!" << RESET << std::endl;
		return;
	}
	std::cout << GREY << "ScavTrap " << this->Name << " attacks " << target 
			  << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints--;
}