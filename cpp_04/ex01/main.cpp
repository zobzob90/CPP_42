/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:58:22 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 12:38:28 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "=== TEST 1: CORRECT POLYMORPHISM WITH ANIMAL ===" << std::endl;
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

	std::cout << "\n=== TEST 2: INCORRECT POLYMORPHISM WITH WRONGANIMAL ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();  // Will call WrongAnimal::makeSound() - no polymorphism!
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n=== TEST 3: BRAIN FUNCTIONALITY ===" << std::endl;
	Dog* smartDog = new Dog();
	Cat* smartCat = new Cat();
	
	// Test Brain ideas
	smartDog->setIdea(0, "Guard the house");
	smartDog->setIdea(1, "Play fetch");
	smartCat->setIdea(0, "Hunt mice");
	smartCat->setIdea(1, "Nap in sunlight");
	
	std::cout << "Dog's first idea: " << smartDog->getIdea(0) << std::endl;
	std::cout << "Cat's first idea: " << smartCat->getIdea(0) << std::endl;

	std::cout << "\n=== TEST 4: DEEP COPY WITH BRAIN ===" << std::endl;
	Dog* dogCopy = new Dog(*smartDog);  // Copy constructor
	std::cout << "Original dog idea: " << smartDog->getIdea(0) << std::endl;
	std::cout << "Copied dog idea: " << dogCopy->getIdea(0) << std::endl;
	
	// Modify original to test deep copy
	smartDog->setIdea(0, "Sleep all day");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original dog idea: " << smartDog->getIdea(0) << std::endl;
	std::cout << "Copied dog idea: " << dogCopy->getIdea(0) << std::endl;

	std::cout << "\n=== TEST 4.5: SCOPE TEST (EVALUATION REQUIREMENT) ===" << std::endl;
	Dog basic;
	basic.setIdea(0, "Basic dog idea");
	std::cout << "Basic dog idea before scope: " << basic.getIdea(0) << std::endl;
	{
		Dog tmp = basic;  // Copy constructor - MUST be deep copy
		std::cout << "Tmp dog idea in scope: " << tmp.getIdea(0) << std::endl;
		tmp.setIdea(0, "Modified in scope");
		std::cout << "Tmp modified: " << tmp.getIdea(0) << std::endl;
		std::cout << "Basic unchanged: " << basic.getIdea(0) << std::endl;
	}  // tmp destructor called here - Brain must be deleted safely
	std::cout << "Basic dog idea after scope: " << basic.getIdea(0) << std::endl;
	std::cout << "✅ If no crash occurred, deep copy works correctly!" << std::endl;

	std::cout << "\n=== TEST 5: ASSIGNMENT OPERATOR ===" << std::endl;
	Dog* anotherDog = new Dog();
	*anotherDog = *smartDog;  // Assignment operator
	std::cout << "Assigned dog idea: " << anotherDog->getIdea(0) << std::endl;

	std::cout << "\n=== TEST 6: ARRAY OF ANIMALS WITH BRAIN ===" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];
	
	// Create half Dogs, half Cats
	for (int k = 0; k < arraySize; k++)
	{
		if (k < arraySize/2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	
	// Test polymorphism and cleanup
	for (int k = 0; k < arraySize; k++)
	{
		std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
		animals[k]->makeSound();
		delete animals[k];  // Test proper Brain destruction
	}

	std::cout << "\n=== TEST 7: ERROR HANDLING ===" << std::endl;
	Dog* testDog = new Dog();
	// Test invalid Brain operations
	testDog->setIdea(-5, "Invalid index");
	testDog->setIdea(150, "Out of bounds");
	std::cout << "Invalid retrieval: " << testDog->getIdea(-1) << std::endl;
	std::cout << "Invalid retrieval: " << testDog->getIdea(99) << std::endl;
	
	// Test empty idea
	testDog->setIdea(0, "");

	std::cout << "\n=== CLEANUP ===" << std::endl;
	delete smartDog;
	delete smartCat;
	delete dogCopy;
	delete anotherDog;
	delete testDog;

	return (0);
}
