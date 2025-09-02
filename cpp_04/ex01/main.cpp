/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:22 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:31:43 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "=== CORRECT POLYMORPHISM WITH ANIMAL ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();  // Will call Cat::makeSound() - polymorphism works!
	j->makeSound();  // Will call Dog::makeSound() - polymorphism works!
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== INCORRECT POLYMORPHISM WITH WRONGANIMAL ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();  // Will call WrongAnimal::makeSound() - no polymorphism!
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	return (0);
}
