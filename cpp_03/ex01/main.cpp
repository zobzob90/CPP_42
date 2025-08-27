/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:23:56 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/27 11:21:37 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap Clap("ClapTrap");
	ClapTrap ClapEnemy("Evil ClapTrap");
	ScavTrap Scav("ScavTrap");
	
	std::cout << std::endl;
	
	Clap.show_info();
	ClapEnemy.show_info();
	Scav.show_info();
	
	std::cout << std::endl;
	
	Clap.attack("Evil ClapTrap");
	ClapEnemy.takeDamage(5);
	ClapEnemy.beRepaired(3);
	ClapEnemy.attack("ClapTrap");
	Clap.takeDamage(11);
	Scav.attack("Evil ClapTrap");
	Scav.guardGate();

	std::cout << std::endl;

	Clap.show_info();
	ClapEnemy.show_info();
	Scav.show_info();

	return (0);
}
