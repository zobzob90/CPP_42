/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:01 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/23 10:25:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	// std::cout << "Presidential Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "Presidential Param Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target)
{
	// std::cout << "President Copy Constructor Called" << std::endl;	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	// std::cout << "Presidential Operator Called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Presidential Destructor Called" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

// Action spécifique du PresidentialPardonForm
// Informe que le target a été gracié par Zaphod Beeblebrox
void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblerox." << std::endl; 
}
