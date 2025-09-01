/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:27 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 18:48:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

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

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(); // constructeur par defaut
		WrongAnimal(const std::string& type); // constructeur avec parametres
		WrongAnimal(const WrongAnimal& src); // constructeur de copie
		WrongAnimal &operator=(const WrongAnimal& src); // operateur d'assignation
		virtual ~WrongAnimal(); // destructeur virtuel important pour le polymorphisme
		void makeSound() const; // methode NON virtuelle - pas de polymorphisme !
		std::string getType() const; // getter pour recuperer le type d'animal
		
} ;

#endif