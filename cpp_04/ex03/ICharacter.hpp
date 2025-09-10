/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:37:13 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 10:44:00 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include <iostream>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}                                     // Destructeur virtuel pour polymorphisme
		virtual	std::string const& getName() const = 0;             // Retourne le nom du personnage
		virtual	void equip(AMateria* m) = 0;                        // Équipe une materia
		virtual void unequip(int idx) = 0;                          // Déséquipe une materia (sans la supprimer)
		virtual void use(int idx, ICharacter& target) = 0;          // Utilise une materia sur une cible
} ;

#endif