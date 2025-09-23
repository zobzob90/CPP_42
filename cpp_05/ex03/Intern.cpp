/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:49:52 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/23 10:25:22 by ertrigna         ###   ########.fr       */
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

// Méthodes factory privées - chacune crée un type spécifique de formulaire
// Pattern Factory: encapsule la création d'objets selon leur type
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
	// Tableau des noms de formulaires acceptés - doit correspondre exactement
	std::string formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	} ;
	
	// Tableau de pointeurs sur fonctions membres - technique avancée pour éviter if/else
	// Chaque élément pointe vers une méthode de création spécifique
	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	} ;
	
	// Parcourir les noms pour trouver une correspondance
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			// Appel de la fonction via pointeur : (objet->*pointeur)(arguments)
			return (this->*formCreators[i])(target);
		}	
	}
	
	// Aucun formulaire trouvé - retourner NULL
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
