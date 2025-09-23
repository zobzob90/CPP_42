/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:27 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/23 10:25:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
	// std::cout << "Bureaucrat Constructor Called" << std::endl;
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	// std::cout << "Bureaucrat Constructor Param Called" << std::endl;

	if (_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{ 
	// std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat Destructor Called" << std::endl;
}

/****GETTER *****/
const std::string& Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

/****INCR + DECR */
// Améliore le grade (diminue la valeur numérique)
// Grade 1 = le plus haut, donc on ne peut pas incrémenter depuis 1
void Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	--_grade;
}

// Dégrade le grade (augmente la valeur numérique)
// Grade 150 = le plus bas, donc on ne peut pas décrémenter depuis 150
void Bureaucrat::decrementGrade()
{
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	++_grade;
}

// Méthode pour signer un formulaire
// Utilise try/catch pour gérer les exceptions et afficher un message approprié
void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

// Méthode pour exécuter un formulaire 
// Appelle la méthode execute() du formulaire qui gère les vérifications
void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " could not execute " << form.getName() << " because " <<  e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrate grade: " << bureaucrat.getGrade();
	return os;
}

/****EXCEPTIONS ****/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
