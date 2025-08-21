/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:50 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/21 13:37:51 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ()
{
	std::cout << "🔨" << GREEN << " ClapTrap constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string Name)
{
	std::cout << "🤖" << RED << " ClapTrap is initialized" << RESET << std::endl;
	this->Name = Name;
	this->hitPoints = 10;
	this->attackDamage = 0;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "🦾" << GREY << " ClapTrap copy constructor called" << RESET << std::endl;
	this->Name = src.Name;
	this->hitPoints = src.hitPoints;
	this->attackDamage = src.attackDamage;
	this->energyPoints = src.energyPoints;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "🔀" << CYAN << " ClapTrap assignement operator sent" << RESET << std::endl;
	if (this != &src)
	{
		this->Name = src.Name;
		this->hitPoints = src.hitPoints;
		this->attackDamage = src.attackDamage;
		this->energyPoints = src.energyPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "💣" << YELLOW << " DESTRUCTOR CALLED" << RESET << std::endl; 
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "🤺" << RED << " [ATTACK]" << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << "ClapTrap" << this->Name << " has no energy points left" << std::endl;
	else if (hitPoints <= 0)
		std::cout << GREY << "ClapTrap" << this->Name << " has no hit points left and cannot attacks !" << std::endl;
	else
	{
		std::cout << GREY << "ClapTrap" << this->Name << " attacks," << target << " causing" << this->attackDamage << " points of damage !" << std::endl;
		this->energyPoints-- ;
	}
}


void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "💥" << GOLD << " [DAMAGE]" << RESET << std::endl;
	if (this->hitPoints <= 0)
		std::cout << GREY << "ClapTrap " << this->Name << "is already destroy" << std::endl;
	else
	{
		
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "❤️‍🩹" << GOLD << " [REPAIR]" << RESET << std::endl;
	if (this->energyPoints <= 0)
	{
		std::cout << GREY << "ClapTrap " << this->Name << " has no energy points left to repair!" << RESET << std::endl;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << GREY << "ClapTrap " << this->Name << " cannot repair itself when destroyed!" << RESET << std::endl;
	}
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << GREY << "ClapTrap " << this->Name << " repairs itself for " << amount << " hit points! Current HP: " << this->hitPoints << ", Energy: " << this->energyPoints << RESET << std::endl;
	}
}

void	ClapTrap::show_info()
{
	std::cout << "📊" << BLUE << " [INFO] ClapTrap " << this->Name << RESET << std::endl;
	std::cout << GREY << "  Hit Points: " << this->hitPoints << std::endl;
	std::cout << "  Energy Points: " << this->energyPoints << std::endl;
	std::cout << "  Attack Damage: " << this->attackDamage << RESET << std::endl;
}
