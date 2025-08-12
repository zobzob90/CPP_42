/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:33:28 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 12:55:45 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon) : name(name), weapon(weapon){}
HumanA::~HumanA(){}

void HumanA::Attack()
{
	std::cout << RED << BOLD << name << NC << " attacks with his " << CYAN << weapon.getType() << NC << " ⚔️" << std::endl;
}
