/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:49:52 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 18:06:47 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Intern Operator Called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new Robotomy(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	} ;
	
	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	} ;
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}	
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
