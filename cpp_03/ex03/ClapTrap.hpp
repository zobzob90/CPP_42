/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:53 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 15:18:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"
#define BLUE "\033[34m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define GOLD "\033[33;1m"
#define PINK "\033[35m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

class	ClapTrap
{
	protected:
		std::string Name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string Name); //constructeur
		ClapTrap(const ClapTrap& src); //Copy constructeur
		ClapTrap &operator=(const ClapTrap& src); // Assignement 
		~ClapTrap(); //destructeur
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	show_info();
} ;

#endif