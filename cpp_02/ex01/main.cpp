/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:41 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:30:58 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;                        // Constructeur par défaut
	Fixed	const b( 10 );            // Constructeur avec int (10)
	Fixed	const c( 42.42f);         // Constructeur avec float (42.42)
	Fixed const d ( b );              // Constructeur de copie (d = copie de b)
	
	a = Fixed( 1234.4321f );          // Affectation avec un objet temporaire
	
	// Affichage des valeurs en float (via l'opérateur <<)
	std::cout << "a is " << a <<  std::endl;
	std::cout << "b is " << b <<  std::endl;
	std::cout << "c is " << c <<  std::endl;
	std::cout << "d is " << d <<  std::endl;

	// Affichage des valeurs converties en int (partie entière)
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return (0);
}
