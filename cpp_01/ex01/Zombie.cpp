/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:38:22 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 15:54:46 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << name << ": destroyed" << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->name = name;
}

void	Zombie::announce() const
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
