/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:49:54 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 16:14:22 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);
	
	private :
		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);
} ;

#endif