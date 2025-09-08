/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:28:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:04 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Color.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Prison.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Prison());
	
	AMateria* tmp;
	AMateria* tmp2;
	AMateria* tmp3;

	ICharacter* Kaaris = new Character("Kaaris");
	ICharacter* Booba = new Character("Booba");
	ICharacter* Justice = new Character("French Justice");
	
	std::cout << std::endl;
	std::cout << "		Two contenders arrive at Orly Airport ! 🛫" << std::endl;
	std::cout << std::endl;
	std::cout << "A wild contender arrive: " << RED << Kaaris->getName() << RESET << std::endl;
	std::cout << "Another wild contender arrive: " << RED << Booba->getName() << RESET << std::endl;
	std::cout << std::endl;
 
	std::cout << "In the blue corner 🟦 : " << BLUE << Kaaris->getName() << " 😤" << RESET << std::endl; 
	tmp = src->createMateria("ice");
	Kaaris->equip(tmp);
	tmp = src->createMateria("cure");
	Kaaris->equip(tmp);
	std::cout << std::endl;
	
	std::cout << "In the red corner 🟥 : " << RED << Booba->getName() << " 😎"<< RESET << std::endl; 
	tmp2 = src->createMateria("fire");
	Booba->equip(tmp2);
	tmp2 = src->createMateria("cure");
	Booba->equip(tmp2);
	std::cout << std::endl;
	
	std::cout << BLINK << GOLD << "		FIGHT !		" << RESET << std::endl;
	Kaaris->use(0, *Booba);
	Kaaris->use(1, *Booba);
	Booba->use(0, *Kaaris);
	Booba->use(1, *Kaaris);
	std::cout << std::endl;
	std::cout << "But what ?! Here's another contender : " << RED << Justice->getName() << RESET << " 👨‍⚖️ " << std::endl;
	tmp3 = src->createMateria("prison");
	Justice->equip(tmp3);
	Justice->use(0, *Booba);
	Justice->use(0, *Kaaris);
	std::cout << std::endl;
	std::cout << BLINK << GREEN << "		The French Justice is ending the fight !	" << RESET << std::endl;


	delete Booba;
	delete Kaaris;
	delete Justice;
	delete src;

	return (0);
}
