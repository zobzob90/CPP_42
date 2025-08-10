/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:17 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/10 19:13:33 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
