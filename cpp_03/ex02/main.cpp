/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:56 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/29 15:01:32 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap Clap("ClapTrap");
	ScavTrap Scav("ScavTrap");
	FragTrap Frag("FragTrap");
	
	std::cout << std::endl;
	
	Clap.show_info();
	Scav.show_info();
	Frag.show_info();
	
	std::cout << std::endl;
	
	Clap.attack("ScavTrap");
	Scav.takeDamage(11);
	Scav.attack("ClapTrap");
	Scav.guardGate();
	Clap.beRepaired(5);
	Frag.highFiveGuys();

	std::cout << std::endl;

	Clap.show_info();
	Scav.show_info();
	Frag.show_info();

	return (0);
}
