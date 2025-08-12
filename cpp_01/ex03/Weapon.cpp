/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:33:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 12:00:27 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::~Weapon(){}

Weapon::Weapon(const std::string& type) : type(type){}

const std::string& Weapon::getType() const
{
	return (type); //retourne une reference
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;	//on utilise this pour eviter une ambiguite
}
