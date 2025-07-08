/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/07/08 11:26:39 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	// donnee personnelle de chaque contact en privee
	private:
		std::string first_name;
		std::string last_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact(); // constructeur pour creer un contact
		~Contact(); // destructeur pour detruire un contact
	
	//Setters Fonctions public qui permettent de modifier les donnees personnelles privees
	void	set_first_name(const std::string& first_name);
	void	set_last_name(const std::string& last_name);
	void	set_phone_number(const std::string& phone_number);
	void	set_secret(const std::string& darkest_secret);

	//Getters Fonctions qui retournent les valeurs privees des donnes perso de chaque contact
	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_phone_number() const;
	std::string	get_secret() const;
};
#endif