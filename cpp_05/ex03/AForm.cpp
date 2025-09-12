/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:55:39 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 13:10:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Construct
AForm::AForm() : _nameAForm("Default"), _isSigned(false), _gradeToSigned(150), _gradeToExecute(150)
{
	// std::cout << "AForm Default Constructor Called" << std::endl;
}

//Param
AForm::AForm(const std::string& name, int gradeToSigned, int gradeToExecute) : _nameAForm(name), _isSigned(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm Param Constructor Called" << std::endl;
	if (_gradeToSigned < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSigned > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

//Copy
AForm::AForm(const AForm& src) : _nameAForm(src._nameAForm), _isSigned(src._isSigned), _gradeToSigned(src._gradeToSigned), _gradeToExecute(src._gradeToExecute)
{
	// std::cout << "AForm Copy Constructor Called" << std::endl;	
}

//Operator
AForm &AForm::operator=(const AForm& src)
{
	if (this != &src)
		_isSigned = src._isSigned;
	return (*this);
}

//destructor
AForm::~AForm()
{
	// std::cout << "Form Destructor Called" << std::endl;
} 

/**** GETTER PART ****/
const	std::string& AForm::getName() const
{
	return _nameAForm;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int	AForm::getGradeToSigned() const
{
	return _gradeToSigned;
}

int	AForm::GetGradeToExecute() const
{
	return _gradeToExecute;
}

// verifie si le getGrade du Bureaucrat est plus grand que le grade a signer si il ne l'est pas retourne true au boleen isSigned de la class Form
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSigned)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

/****EXCEPTIONS ****/
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "For is not signed you donkey !";
}

// OSTREAM OPERATOR
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os	<< "Form \""<< form.getName() << "\" "
		<< (form.getIsSigned() ? "[signed]" : "[not signed]")
		<< " (sign:" << form.getGradeToSigned()
		<< ", exec:" << form.GetGradeToExecute() << ")"; 
	return os;
}