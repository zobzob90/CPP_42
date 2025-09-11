/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:46 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 15:57:08 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//Construct
Form::Form() : _nameForm("Default"), _isSigned(false), _gradeToSigned(150), _gradeToExecute(150)
{
	// std::cout << "Form Default Constructor Called" << std::endl;
}

//Param
Form::Form(const std::string& name, int gradeToSigned, int gradeToExecute) : _nameForm(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute)
{
	// std::cout << "Form Param Constructor Called" << std::endl;
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

//Copy
Form::Form(const Form& src) : _nameForm(src._nameForm), _isSigned(src._isSigned), _gradeToSigned(src._gradeToSigned), _gradeToExecute(src._gradeToExecute)
{
	// std::cout << "Form Copy Constructor Called" << std::endl;	
}

//Operator
Form &Form::operator=(const Form& src)
{
	if (this != &src)
		_isSigned = src._isSigned;
	return (*this);
}

//destructor
Form::~Form()
{
	// std::cout << "Form Destructor Called" << std::endl;
} 

/**** GETTER PART ****/
const	std::string& Form::getName() const
{
	return _nameForm;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int	Form::getGradeToSigned() const
{
	return _gradeToSigned;
}

int	Form::GetGradeToExecute() const
{
	return _gradeToExecute;
}

// verifie si le getGrade du Bureaucrat est plus grand que le grade a signer si il ne l'est pas retourne true au boleen isSigned de la class Form
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSigned)
		throw GradeTooLowException();
	_isSigned = true;
}

/****EXCEPTIONS ****/
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// OSTREAM OPERATOR
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os	<< "Form \""<< form.getName() << "\" "
		<< (form.getIsSigned() ? "[signed]" : "[not signed]")
		<< " (sign:" << form.getGradeToSigned()
		<< ", exec:" << form.GetGradeToExecute() << ")"; 
	return os;
}
