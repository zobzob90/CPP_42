/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:38:17 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 15:40:32 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), Name("Default")
{
	ClapTrap::Name = "Default_clap_name";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name +"_clap_name"), Name(name)
{
	ClapTrap::Name = name + "_clap_name";
	std::cout << "🤖" << RED << " DiamondTrap is initialized : " << Name << RESET << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "🔀" << CYAN << " DiamondTrap assignement operator sent" << RESET << std::endl;
	if (this != &src)
	{
		ScavTrap::operator=(src);
		this->Name = src.Name;
		ClapTrap::Name = src.ClapTrap::Name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "💣" << " DIAMONDTRAP DESTRUCTOR CALLED" << RESET << std::endl; 
}

void	DiamondTrap:: whoAmI()
{
	std::cout << RED << "Who Am I : " << this->Name << " , ClapTrap Name " << ClapTrap::Name << RESET << std::endl;
}
