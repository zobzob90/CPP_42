/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:41 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:44:37 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Tests de base (du sujet)
	Fixed	a;
	Fixed	const	b ( Fixed( 5.05f ) * Fixed ( 2 ));

	std::cout << "=== Tests de base ===" << std::endl;
	std::cout << "a (défaut): " << a << std::endl;                    // 0
	std::cout << "++a: " << ++a << std::endl;                         // Pré-incrémentation
	std::cout << "a après ++a: " << a << std::endl;                   // Valeur après pré-inc
	std::cout << "a++: " << a++ << std::endl;                         // Post-incrémentation
	std::cout << "a après a++: " << a << std::endl;                   // Valeur après post-inc

	std::cout << "b (5.05 * 2): " << b << std::endl;                  // 10.1
	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl;    // Plus petit
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;    // Plus grand

	// Tests supplémentaires
	std::cout << "\n=== Tests des constructeurs ===" << std::endl;
	Fixed c(42);           // Constructeur int
	Fixed d(3.14f);        // Constructeur float
	Fixed e(c);            // Constructeur de copie

	std::cout << "c (int 42): " << c << std::endl;
	std::cout << "d (float 3.14): " << d << std::endl;
	std::cout << "e (copie de c): " << e << std::endl;

	std::cout << "\n=== Tests des opérateurs arithmétiques ===" << std::endl;
	std::cout << "c + d: " << c + d << std::endl;                     // 42 + 3.14 = 45.14
	std::cout << "c - d: " << c - d << std::endl;                     // 42 - 3.14 = 38.86
	std::cout << "c * d: " << c * d << std::endl;                     // 42 * 3.14 = 131.88
	std::cout << "c / d: " << c / d << std::endl;                     // 42 / 3.14 ≈ 13.375

	std::cout << "\n=== Tests des opérateurs de comparaison ===" << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;                 // false (42 != 3.14)
	std::cout << "c != d: " << (c != d) << std::endl;                 // true
	std::cout << "c > d: " << (c > d) << std::endl;                   // true (42 > 3.14)
	std::cout << "c < d: " << (c < d) << std::endl;                   // false
	std::cout << "c >= d: " << (c >= d) << std::endl;                 // true
	std::cout << "c <= d: " << (c <= d) << std::endl;                 // false

	std::cout << "\n=== Tests de décrémentation ===" << std::endl;
	Fixed f(10.5f);
	std::cout << "f initial: " << f << std::endl;                     // 10.5
	std::cout << "--f: " << --f << std::endl;                         // Pré-décrémentation
	std::cout << "f après --f: " << f << std::endl;
	std::cout << "f--: " << f-- << std::endl;                         // Post-décrémentation
	std::cout << "f après f--: " << f << std::endl;

	std::cout << "\n=== Tests des conversions ===" << std::endl;
	Fixed g(123.456f);
	std::cout << "g (123.456): " << g << std::endl;
	std::cout << "g.toInt(): " << g.toInt() << std::endl;             // Partie entière
	std::cout << "g.toFloat(): " << g.toFloat() << std::endl;         // Valeur float
	std::cout << "g.getRawBits(): " << g.getRawBits() << std::endl;   // Valeur brute

	return (0);
}
