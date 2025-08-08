/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:45:21 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/08 16:30:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int		oldest_contact;
		int		contact_count;
		bool	is_empty(const std::string &str) const;
		bool	is_alnum(const std::string &str) const;
		bool	is_validnum(const std::string &str) const;
		std::string isValid(const std::string& prompt, bool numericOnly);
		
	public:
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	search_contact();
		void	print_contact();
};

#endif