/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 14:00:08 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

/*
** Classe Contact - Representation d'un contact individuel
** 
** Cette classe encapsule toutes les informations personnelles d'un contact.
** Tous les attributs sont prives pour respecter le principe d'encapsulation.
** L'acces aux donnees se fait uniquement via les getters/setters publics.
*/
class	Contact
{
	private:
		// === DONNEES PERSONNELLES PRIVEES ===
		// Ces attributs ne sont accessibles que par les methodes de la classe
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		// === CONSTRUCTEUR ET DESTRUCTEUR ===
		Contact(); 		// Constructeur par defaut - cree un contact vide
		~Contact(); 	// Destructeur - libere les ressources si necessaire
		// === SETTERS - METHODES DE MODIFICATION ===
		// Ces fonctions permettent de modifier les donnees privees en toute securite
		void	set_first_name(const std::string& first_name);		// Definit le prenom
		void	set_last_name(const std::string& last_name);		// Definit le nom
		void 	set_nickname(const std::string& nickname);			// Definit le surnom
		void	set_phone_number(const std::string& phone_number);	// Definit le numero
		void	set_secret(const std::string& darkest_secret);		// Definit le secret

		// === GETTERS - METHODES D'ACCES EN LECTURE ===
		// Ces fonctions retournent les valeurs des attributs privees
		// Le mot-cle 'const' garantit qu'elles ne modifient pas l'objet
		std::string	get_first_name() const;		// Retourne le prenom
		std::string	get_last_name() const;		// Retourne le nom
		std::string	get_nickname() const;		// Retourne le surnom
		std::string	get_phone_number() const;	// Retourne le numero
		std::string	get_secret() const;			// Retourne le secret
};

#endif