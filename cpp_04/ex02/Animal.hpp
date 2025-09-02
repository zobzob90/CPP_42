/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:09 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:54:57 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define PINK "\033[35m"
#define WHITE "\033[37m"
#define GREY "\033[90m"
#define BLACK "\033[30m"
#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

class Animal
{
	protected :
		std::string type;
	public :
		Animal(); // constructeur par defaut
		Animal(const std::string& type); // constructeur avec parametres
		Animal(const Animal& src); // constructeur de copie
		Animal &operator=(const Animal& src); // operateur d'assignation
		virtual ~Animal(); // destructeur virtuel important pour le polymorphisme
		virtual void makeSound() const = 0; // methode virtuelle pour emettre un son dans les autres classes
		std::string getType() const; // getter pour recuperer le type d'animal
} ;

#endif