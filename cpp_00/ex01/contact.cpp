/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/07/08 13:07:01 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::set_first_name(const std::string& first_name)
{
	this->first_name = first_name; //this permet de modifier l'attribut courant
}

void	Contact::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}

void	Contact::set_phone_number(const std::string& phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_secret(const std::string& darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name() const
{
	return (first_name);
}

std::string Contact::get_last_name() const
{
	return (last_name);	
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

std::string Contact::get_secret() const
{
	return (darkest_secret);
}
