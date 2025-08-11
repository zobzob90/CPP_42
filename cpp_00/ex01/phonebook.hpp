/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:21 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 13:59:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_HPP
#define BOOK_HPP

// Inclusions des bibliotheques necessaires
#include <iostream>		// pour std::cout, std::cin
#include <iomanip>		// pour std::setw() (formatage des colonnes)
#include <cstring>		// pour les fonctions C de manipulation de chaines
#include <string>		// pour std::string
#include <cctype>		// pour std::isdigit() (verification des caracteres)
#include <cstdlib>		// pour std::atoi() (conversion string vers int)
#include "contact.hpp"	// inclusion de notre classe Contact

/*
** Classe Phonebook - Repertoire telephonique
** 
** Cette classe gere un repertoire de maximum 8 contacts.
** Quand le repertoire est plein, le contact le plus ancien est remplace
** par le nouveau contact (comportement FIFO - First In, First Out).
*/
class Phonebook
{
	private:
		// === ATTRIBUTS PRIVES ===
		Contact contacts[8];		// Tableau fixe de 8 contacts maximum
		int		oldest_contact;		// Index du contact le plus ancien (pour rotation)
		int		contact_count;		// Nombre actuel de contacts (0 a 8)
		
		// === METHODES UTILITAIRES PRIVEES ===
		// Ces methodes ne sont utilisees qu'en interne par la classe
		bool	is_empty(const std::string &str) const;			// Verifie si une chaine est vide
		bool	is_alnum(const std::string &str) const;			// Verifie si une chaine ne contient que des chiffres
		bool	is_validnum(const std::string &str) const;		// Valide un numero de telephone (6-15 chiffres)
		std::string isValid(const std::string& prompt, bool num_only);	// Demande une saisie valide a l'utilisateur
		std::string	truncate10(const std::string& str) const;	// Tronque une chaine a 10 caracteres max
		
	public:
		// === CONSTRUCTEUR ET DESTRUCTEUR ===
		Phonebook();	// Initialise le repertoire vide
		~Phonebook();	// Destructeur (nettoyage si necessaire)
		
		// === INTERFACE PUBLIQUE ===
		// Ces methodes constituent l'API de la classe, utilisables de l'exterieur
		void	add_contact();		// Ajoute un nouveau contact (commande ADD)
		void	search_contact();	// Recherche et affiche les contacts (commande SEARCH)
};

#endif