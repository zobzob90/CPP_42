/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:19 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:58:31 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& src);
		Dog &operator=(const Dog& src);
		virtual ~Dog();
		void	makeSound() const;
		std::string getType() const;
		std::string getIdea(int index) const; //getter
		void setIdea(int index, const std::string& idea); //setter
} ;

#endif