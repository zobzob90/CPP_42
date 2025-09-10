/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:45 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 10:36:52 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];		// Inventaire principal : 4 slots pour les materia équipées
		AMateria* _unequiped[4];		// Stockage temporaire pour les materia déséquipées (évite les fuites)
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& src);
		Character &operator=(const Character& src);
		virtual ~Character();

		/* Méthodes héritées de ICharacter (obligatoires) */
		virtual std::string const & getName() const;		// Retourne le nom du personnage
		virtual	void equip(AMateria* m);					// Équipe une materia dans le premier slot libre
		virtual void unequip(int idx);						// Déséquipe une materia et la stocke temporairement
		virtual void use(int idx, ICharacter& target);		// Utilise la materia du slot idx sur la cible
		
		/* Méthode utilitaire */
		bool	fullInventory();							// Vérifie si l'inventaire est plein (4/4 slots)
		
} ;

#endif