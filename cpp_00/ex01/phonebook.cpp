/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:19 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 14:05:56 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : oldest_contact(0), contact_count(0){}
Phonebook::~Phonebook() {}

/* Verifie si une chaine de caracteres est vide */
bool	Phonebook::is_empty(const std::string &str) const
{
	return (str.empty());
}

/* Verifie si une chaine ne contient que des chiffres (0-9) */
bool	Phonebook::is_alnum(const std::string &str) const
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		// static_cast securise la conversion pour isdigit()
		if (!std::isdigit(static_cast <unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

/* Valide qu'un numero de telephone respecte les criteres */
bool	Phonebook::is_validnum(const std::string& str) const
{
	if (!is_alnum(str))
		return (false);
	if (str.length() < 6 || str.length() > 15)
		return (false);
	return (true);
}

/*
** Tronque une chaine a 10 caracteres maximum pour l'affichage en colonnes
** Si la chaine fait plus de 10 caracteres, garde les 9 premiers + "."
*/
std::string	Phonebook::truncate10(const std::string& str) const
{
	if (str.length() <= 10)
		return (str);				// Pas besoin de tronquer
	return (str.substr(0, 9) + ".");	// 9 caracteres + point
}

/* Demande une saisie valide a l'utilisateur avec validation */
std::string	Phonebook::isValid(const std::string& prompt, bool num_only)
{
	std::string	input;
	
	while (true)
	{
		std::cout << prompt;	// Affichage du prompt
		
		// Lecture de la ligne avec gestion d'erreur
		if (!std::getline(std::cin, input))
		{
			// Gestion de l'EOF (Ctrl+D)
			if (std::cin.eof())
				std::cout << "\nEOF. Retour.\n";
			return "";	// Retour chaine vide pour signaler l'arret
		}
		// Verification que le champ n'est pas vide
		if (is_empty(input))
		{
			std::cout << "Champ vide\n";
			continue ;	// Redemande la saisie
		}
		// Validation specifique pour les numeros de telephone
		if (num_only)
		{
			if (!is_validnum(input))
			{
				std::cout << "Numero invalide (6-15 chiffres).\n";
				continue ;	// Redemande la saisie
			}
		}
		return (input);	// Saisie valide, on la retourne
	}
}

// === METHODES PUBLIQUES ===

/*
** COMMANDE ADD - Ajoute un nouveau contact au repertoire
** 
** Cette methode :
** 1. Demande sequentiellement tous les champs du contact
** 2. Valide chaque entree (champs vides interdits, numero valide)
** 3. Gere la rotation automatique si le repertoire est plein (8 contacts max)
** 4. Affiche l'index d'enregistrement du contact
*/
void	Phonebook::add_contact()
{
	Contact		new_contact;	// Creation d'un nouveau contact temporaire
	std::string	input;			// Variable pour stocker les saisies
	int			index;			// Index ou sera stocke le contact

	// === SAISIE DU PRENOM ===
	input = isValid("Prenom: ", false);	// false = pas de validation numerique
	if (input.empty())	// Si EOF detecte, on sort
		return ;
	new_contact.set_first_name(input);
	
	// === SAISIE DU NOM ===
	input = isValid("Nom: ", false);
	if (input.empty())
		return ;
	new_contact.set_last_name(input);

	// === SAISIE DU SURNOM ===
	input = isValid("Surnom: ", false);
	if (input.empty())
		return ;
	new_contact.set_nickname(input);

	// === SAISIE DU NUMERO (avec validation) ===
	input = isValid("Numero de telephone: ", true);	// true = validation numerique
	if (input.empty())
		return ;
	new_contact.set_phone_number(input);

	// === SAISIE DU SECRET ===
	input = isValid("Secret le plus sombre: ", false);
	if (input.empty())
		return ;
	new_contact.set_secret(input);
	
	// === STOCKAGE DU CONTACT ===
	if (contact_count < 8)
	{
		// Repertoire pas encore plein : ajout simple
		index = contact_count;
		contacts[index] = new_contact;
		contact_count++;
	}
	else
	{
		// Repertoire plein : rotation (remplace le plus ancien)
		index = oldest_contact;
		contacts[index] = new_contact;
		oldest_contact = (oldest_contact + 1) % 8;	// Rotation circulaire
	}
	
	// Confirmation a l'utilisateur
	std::cout << "Contact enregistre a l'index " << index << "\n";
}

/*
** COMMANDE SEARCH - Recherche et affiche les contacts
** 
** Cette methode :
** 1. Verifie qu'il y a au moins un contact
** 2. Affiche tous les contacts sous forme de tableau formate (colonnes de 10 caracteres)
** 3. Demande a l'utilisateur de choisir un index
** 4. Valide l'index et affiche les details complets du contact choisi
*/
void	Phonebook::search_contact()
{
	// Verification qu'il y a des contacts a afficher
	if (contact_count == 0)
	{
		std::cout << "Aucun contact. \n";
		return ;
	}
	
	// === AFFICHAGE DU TABLEAU (EN-TETE) ===
	// Utilisation de std::setw(10) pour des colonnes de 10 caracteres
	std::cout << std::setw(10) << "Index" << "|" 
			<< std::setw(10) << "Prenom" << "|"
			<< std::setw(10) << "Nom" << "|"
			<< std::setw(10) << "Surnom" << "\n";
			
	// === AFFICHAGE DES CONTACTS (DONNEES) ===
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncate10(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << truncate10(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << truncate10(contacts[i].get_nickname()) << "\n";
	}
	
	// === SELECTION D'UN CONTACT ===
	std::string idx;	
	std::cout << "Index a afficher: ";

	// Lecture de l'index avec gestion d'erreur
	if (!std::getline(std::cin, idx))
	{
		std::cout << "\n Lecture interrompue.\n";
		return ;
	}
	
	// Validation que l'index ne contient que des chiffres et est raisonnable
	if (!is_alnum(idx) || idx.length() > 2)
	{
		std::cout << "Index invalide.\n";
		return ;
	}
	
	// Conversion string vers int et verification des limites
	int num = std::atoi(idx.c_str());
	if (num < 0 || num >= contact_count)
	{
		std::cout << "Hors limite.\n";
		return ;
	}
	
	// === AFFICHAGE DETAILLE DU CONTACT SELECTIONNE ===
	std::cout << "Prénom: " << contacts[num].get_first_name() << "\n";
    std::cout << "Nom: " << contacts[num].get_last_name() << "\n";
    std::cout << "Surnom: " << contacts[num].get_nickname() << "\n";
    std::cout << "Téléphone: " << contacts[num].get_phone_number() << "\n";
    std::cout << "Secret: " << contacts[num].get_secret() << "\n";
}
