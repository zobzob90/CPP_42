/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:17 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 14:01:02 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** FONCTION PRINCIPALE - Point d'entree du programme
** 
** Cette fonction implemente la boucle Read-Eval-Print (REPL) :
** 1. Lit une commande de l'utilisateur (READ)
** 2. Evalue et execute la commande (EVAL) 
** 3. Affiche le resultat et recommence (PRINT + LOOP)
**
** Commandes supportees :
** - ADD    : Ajouter un nouveau contact
** - SEARCH : Rechercher et afficher les contacts
** - EXIT   : Quitter le programme proprement
*/
int main()
{
	Phonebook	book;
	std::string	cmd;
	while (true)
	{
		std::cout << "Commande (ADD, SEARCH, EXIT): \n";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "\nEOF. Fin\n";
			break ;
		}
		if (cmd == "ADD")
			book.add_contact();
		else if (cmd == "SEARCH")
			book.search_contact();
		else if (cmd == "EXIT")
			break;
		else if (!cmd.empty())
			std::cout << "Commande inconnue. \n";
	}
	return (0);
}
