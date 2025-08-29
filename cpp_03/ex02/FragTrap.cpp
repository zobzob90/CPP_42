/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:02:53 by eric              #+#    #+#             */
/*   Updated: 2025/08/29 15:08:37 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() // constructeur
{
	std::cout << "🔨" << GREEN << " FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "🤖" << RED << " FragTrap Class is initialized: " << name << RESET << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "🦾" << GREY << " FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& src)
{
	std::cout << "🔀" << CYAN << " FragTrap assignement operator sent" << RESET << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "💣" << YELLOW << " FRAGTRAP DESTRUCTOR CALLED" << RESET << std::endl; 
}

void	FragTrap::highFiveGuys()
{
	std::cout << "👋" << RED  << " High Five Guys" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << "🤺" << RED << " [ATTACK]" << RESET << std::endl;
	if (this->energyPoints <= 0)
		std::cout << GREY << "FragTrap " << this->Name << " has no energy points left!" << RESET << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << GREY << "FragTrap " << this->Name << " has no hit points left and cannot attack!" << RESET << std::endl;
	else
	{
		std::cout << GREY << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
		this->energyPoints--;
	}
}
