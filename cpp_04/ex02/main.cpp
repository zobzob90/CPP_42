/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:22 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 11:00:36 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "=== TEST 1: BASIC POLYMORPHISM ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();  // Will call Cat::makeSound() - polymorphism works!
	j->makeSound();  // Will call Dog::makeSound() - polymorphism works!

	delete j;
	delete i;

	std::cout << "\n=== TEST 2: BRAIN FUNCTIONALITY ===" << std::endl;
	Dog* dog1 = new Dog();
	Cat* cat1 = new Cat();
	
	// Test setting and getting ideas
	dog1->setIdea(0, "Chase the mailman");
	dog1->setIdea(1, "Fetch the ball");
	cat1->setIdea(0, "Knock things off the table");
	cat1->setIdea(1, "Sleep in a sunny spot");
	
	std::cout << "Dog idea 0: " << dog1->getIdea(0) << std::endl;
	std::cout << "Dog idea 1: " << dog1->getIdea(1) << std::endl;
	std::cout << "Cat idea 0: " << cat1->getIdea(0) << std::endl;
	std::cout << "Cat idea 1: " << cat1->getIdea(1) << std::endl;

	std::cout << "\n=== TEST 3: DEEP COPY (COPY CONSTRUCTOR) ===" << std::endl;
	Dog* dog2 = new Dog(*dog1);  // Copy constructor
	Cat* cat2 = new Cat(*cat1);  // Copy constructor
	
	std::cout << "Original dog idea 0: " << dog1->getIdea(0) << std::endl;
	std::cout << "Copied dog idea 0: " << dog2->getIdea(0) << std::endl;
	
	// Modify original to test deep copy
	dog1->setIdea(0, "Modified idea");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original dog idea 0: " << dog1->getIdea(0) << std::endl;
	std::cout << "Copied dog idea 0: " << dog2->getIdea(0) << std::endl;

	std::cout << "\n=== TEST 4: ASSIGNMENT OPERATOR ===" << std::endl;
	Dog* dog3 = new Dog();
	*dog3 = *dog1;  // Assignment operator
	std::cout << "Assigned dog idea 0: " << dog3->getIdea(0) << std::endl;

	std::cout << "\n=== TEST 5: ARRAY OF ANIMALS ===" << std::endl;
	const int size = 6;
	Animal* animals[size];
	
	// Fill array with half Dogs and half Cats
	for (int k = 0; k < size; k++)
	{
		if (k < size/2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	
	// Test polymorphism in array
	for (int k = 0; k < size; k++)
	{
		std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
		animals[k]->makeSound();
	}
	
	// Clean up array
	for (int k = 0; k < size; k++)
		delete animals[k];

	std::cout << "\n=== TEST 6: ERROR HANDLING ===" << std::endl;
	Dog* dog4 = new Dog();
	// Test invalid index
	dog4->setIdea(-1, "Invalid negative index");
	dog4->setIdea(100, "Invalid high index");
	std::cout << "Invalid idea retrieval: " << dog4->getIdea(-1) << std::endl;
	std::cout << "Invalid idea retrieval: " << dog4->getIdea(100) << std::endl;
	
	// Test empty idea
	dog4->setIdea(0, "");

	std::cout << "\n=== CLEANUP ===" << std::endl;
	delete dog1;
	delete dog2;
	delete dog3;
	delete dog4;
	delete cat1;
	delete cat2;

	std::cout << "\n✅ All tests completed successfully!" << std::endl;
	return (0);
}
