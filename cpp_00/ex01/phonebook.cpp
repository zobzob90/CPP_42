/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:19 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/08 16:45:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : contact_count(0), oldest_contact(0){}

bool	Phonebook::is_empty(const std::string &str) const
{
	return (str.empty());
}

bool	Phonebook::is_alnum(const std::string &str) const
{
	if (str.empty())
		return (false);
	for (char c : str)
	{
		if (!std::isdigit(static_cast <unsigned char>(c)))
			return (false);
	}
	return (true);
}

bool	Phonebook::is_validnum(const std::string &str) const
{
	if (!is_alnum(str))
		return (false);
	if (str.length() < 6 || str.length() > 15)
		return (false);
	return (true);
}



void	Phonebook::add_contact()
{
	Contact		new_contact;
	std::string	input;

	input = ;
}
