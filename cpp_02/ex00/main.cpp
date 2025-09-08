/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:46 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 13:19:17 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	// Création d'un objet Fixed avec le constructeur par défaut
    // stock_num sera initialisé à 0
	Fixed a;
	
	// Création d'un objet Fixed avec le constructeur de copie
    // b est une copie de a, donc stock_num de b = stock_num de a
	Fixed b(a);

	// Création d'un autre objet Fixed avec le constructeur par défaut
    // stock_num sera initialisé à 0
	Fixed c;

	// Utilisation de l'opérateur d'affectation
    // c prend la valeur de b (c.stock_num = b.stock_num)
	c = b;

	std::cout << a.getRawBits() << std::endl; // Affichage de la valeur brute de a (devrait être 0)
	std::cout << b.getRawBits() << std::endl; // Affichage de la valeur brute de b (devrait être 0, copie de a)
	std::cout << c.getRawBits() << std::endl; // Affichage de la valeur brute de c (devrait être 0, assigné depuis b)

	return (0);
}
