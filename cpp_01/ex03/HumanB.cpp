/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:33:35 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 12:55:34 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << GREEN << BOLD << name << NC << " attacks with their " << CYAN << weapon->getType() << NC << " 🏏" << std::endl;
	else
		std::cout << YELLOW << BOLD << name << NC << " attacks with their bare hands 🤜" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
