/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:19 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/10 19:25:33 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : oldest_contact(0), contact_count(0){}
Phonebook::~Phonebook() {}

bool	Phonebook::is_empty(const std::string &str) const
{
	return (str.empty());
}

bool	Phonebook::is_alnum(const std::string &str) const
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast <unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

bool	Phonebook::is_validnum(const std::string& str) const
{
	if (!is_alnum(str))
		return (false);
	if (str.length() < 6 || str.length() > 15)
		return (false);
	return (true);
}

std::string	Phonebook::truncate10(const std::string& str) const
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

std::string	Phonebook::isValid(const std::string& prompt, bool num_only)
{
	std::string	input;
	
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				std::cout << "\nEOF. Retour.\n";
			return "";
		}
		if (is_empty(input))
		{
			std::cout << "Champ vide\n";
			continue ;
		}
		if (num_only)
		{
			if (!is_validnum(input))
			{
				std::cout << "Numero invalide (6-15 chiffres).\n";
				continue ;
			}
		}
		return (input);
	}
}

void	Phonebook::add_contact()
{
	Contact		new_contact;
	std::string	input;
	int			index;

	input = isValid("Prenom: ", false);
	if (input.empty())
		return ;
	new_contact.set_first_name(input);
	
	input = isValid("Nom: ", false);
	if (input.empty())
		return ;
	new_contact.set_last_name(input);

	input = isValid("Surnom: ", false);
	if (input.empty())
		return ;
	new_contact.set_nickname(input);

	input = isValid("Numero de telephone: ", true);
	if (input.empty())
		return ;
	new_contact.set_phone_number(input);

	input = isValid("Secret le plus sombre: ", false);
	if (input.empty())
		return ;
	new_contact.set_secret(input);
	
	if (contact_count < 8)
	{
		index = contact_count;
		contacts[index] = new_contact;
		contact_count++;
	}
	else
	{
		index = oldest_contact;
		contacts[index] = new_contact;
		oldest_contact = (oldest_contact + 1) % 8;
	}
	std::cout << "Contact enregistre a l'index " << index << "\n";
}

void	Phonebook::search_contact()
{
	if (contact_count == 0)
	{
		std::cout << "Aucun contact. \n";
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" 
			<< std::setw(10) << "Prenom" << "|"
			<< std::setw(10) << "Nom" << "|"
			<< std::setw(10) << "Surnom" << "\n";
	for (int i = 0; i < contact_count; i++)
	{
		
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncate10(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << truncate10(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << truncate10(contacts[i].get_nickname()) << "\n";
	}
	std::string idx;	
	std::cout << "Index a afficher: ";

	if (!std::getline(std::cin, idx))
	{
		std::cout << "\n Lecture interrompue.\n";
		return ;
	}
	
	if (!is_alnum(idx) || idx.length() > 2)
	{
		std::cout << "Index invalide.\n";
		return ;
	}
	
	int num = std::atoi(idx.c_str());
	if (num < 0 || num >= contact_count)
	{
		std::cout << "Hors limite.\n";
		return ;
	}
	
	std::cout << "Prénom: " << contacts[num].get_first_name() << "\n";
    std::cout << "Nom: " << contacts[num].get_last_name() << "\n";
    std::cout << "Surnom: " << contacts[num].get_nickname() << "\n";
    std::cout << "Téléphone: " << contacts[num].get_phone_number() << "\n";
    std::cout << "Secret: " << contacts[num].get_secret() << "\n";
}