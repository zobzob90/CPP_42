/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/23 10:25:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	// std::cout << "Shrubbery Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "Shrubbery Param Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{
	// std::cout << "Shrubbery Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != & src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Shrubbery Destructor Called" << std::endl;
}

const	std::string& ShrubberyCreationForm::getTarget() const
{
	return _target;
}

// Action spécifique du ShrubberyCreationForm
// Crée un fichier <target>_shrubbery contenant des arbres ASCII
void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	// Vérification que le fichier s'ouvre correctement
	if (!file.is_open())
		throw std::runtime_error("Could'nt create file !");

	// Écriture d'arbres ASCII dans le fichier
	file << "	🌳\n";
    file << "      /|\\\n"; 
    file << "     / | \\\n";
    file << "       |\n";
    file << "       |\n";
    file << "\n";
    file << "    🌲🌳🌲\n";
    file << "   /|\\  /|\\ /|\\\n";
    file << "    |    |   |\n";
	
	file.close();
	std::cout << "Create shrubbery file: " << filename << std::endl;
}
