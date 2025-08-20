/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:50 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/20 17:20:46 by ertrigna         ###   ########.fr       */
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
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "" << CYAN << " ClapTrap assignement operator sent" << RESET << std::endl;
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
	std::cout << "🤺" << RED << " ATTACK" << RESET << std::endl;
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
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}

void	ClapTrap::show_info()
{

}
