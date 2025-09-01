/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:56 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 15:42:36 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap 	Clap("ClapTrap");
	ScavTrap 	Scav("ScavTrap");
	FragTrap 	Frag("FragTrap");
	DiamondTrap	Diamond("DiamondTrap");

	std::cout << std::endl;
	
	Clap.show_info();
	Scav.show_info();
	Frag.show_info();
	Diamond.show_info();
	
	std::cout << std::endl;
	
	Clap.attack("ScavTrap");
	Scav.takeDamage(11);
	Scav.attack("ClapTrap");
	Scav.guardGate();
	Clap.beRepaired(5);
	Frag.highFiveGuys();
	Diamond.attack("ClapTrap");
	Diamond.whoAmI();

	std::cout << std::endl;

	Clap.show_info();
	Scav.show_info();
	Frag.show_info();
	Diamond.show_info();

	std::cout << std::endl;

	return (0);
}
