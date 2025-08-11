/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 13:59:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

// === CONSTRUCTEUR ET DESTRUCTEUR ===

/*
** Constructeur par defaut de la classe Contact
** Initialise un contact vide (tous les champs string sont automatiquement vides)
*/
Contact::Contact() {}

/*
** Destructeur de la classe Contact  
** Aucun nettoyage special necessaire car on utilise des std::string
** (gestion automatique de la memoire par les string)
*/
Contact::~Contact() {}

// === METHODES SETTERS (MODIFICATEURS) ===

/*
** Definit le prenom du contact
** @param first_name : le prenom a assigner (passe par reference constante pour optimisation)
** Le mot-cle 'this' permet de distinguer le parametre de l'attribut de meme nom
*/
void	Contact::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;	// 'this' pointe vers l'objet courant
}

/*
** Definit le nom de famille du contact
** @param last_name : le nom a assigner
*/
void	Contact::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}

/*
** Definit le surnom du contact
** @param nickname : le surnom a assigner
*/
void	Contact::set_nickname(const std::string& nickname)
{
	this->nickname = nickname;
}

/*
** Definit le numero de telephone du contact
** @param phone_number : le numero a assigner (doit etre valide: 6-15 chiffres)
*/
void	Contact::set_phone_number(const std::string& phone_number)
{
	this->phone_number = phone_number;
}

/*
** Definit le secret le plus sombre du contact
** @param darkest_secret : le secret a assigner
*/
void	Contact::set_secret(const std::string& darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

// === METHODES GETTERS (ACCESSEURS EN LECTURE) ===

/*
** Retourne le prenom du contact
** @return : une copie du prenom (std::string)
** Le mot-cle 'const' garantit que cette methode ne modifie pas l'objet
*/
std::string	Contact::get_first_name() const
{
	return (first_name);
}

/*
** Retourne le nom de famille du contact
** @return : une copie du nom
*/
std::string Contact::get_last_name() const
{
	return (last_name);	
}

/*
** Retourne le surnom du contact
** @return : une copie du surnom
*/
std::string Contact::get_nickname() const
{
	return (nickname);	
}

/*
** Retourne le numero de telephone du contact
** @return : une copie du numero
*/
std::string Contact::get_phone_number() const
{
	return (phone_number);
}

/*
** Retourne le secret le plus sombre du contact
** @return : une copie du secret
*/
std::string Contact::get_secret() const
{
	return (darkest_secret);
}
