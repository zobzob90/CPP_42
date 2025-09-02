/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:22:03 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& src);
		Cat &operator=(const Cat& src);
		virtual ~Cat();
		virtual void	makeSound() const;
		std::string getType() const;
		std::string getIdea(int index) const; //getter
		void setIdea(int index, const std::string& idea); //setter
} ;

#endif