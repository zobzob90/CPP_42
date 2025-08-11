/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:12:33 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 15:07:00 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {}
Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

void	Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
