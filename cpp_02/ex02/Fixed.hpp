/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:44 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:43:32 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>      // Pour roundf()
#include <iostream>   // Pour std::ostream

// Classe Fixed : représente un nombre à virgule fixe
// Stocke un nombre décimal dans un entier en utilisant 8 bits pour la partie fractionnaire
class Fixed
{
	private:
		int					stock_num;  // Valeur stockée en format virgule fixe
		static const int	bits = 8;   // Nombre de bits pour la partie fractionnaire (précision)
	
	public:
		// ===== Constructeurs et destructeur =====
		Fixed();                         // Constructeur par défaut (valeur = 0)
		Fixed(const Fixed &value);       // Constructeur de copie
		Fixed(int const &value);         // Constructeur avec int (convertit en virgule fixe)
		Fixed(float const &value);       // Constructeur avec float (convertit en virgule fixe)
		~Fixed();                        // Destructeur
		
		Fixed &operator=(const Fixed &rhs); // Opérateur d'affectation (a = b)

		// ===== Opérateurs de comparaison =====
		bool operator>(const Fixed&rhs) const;   // Plus grand que (a > b)
		bool operator<(const Fixed&rhs) const;   // Plus petit que (a < b)
		bool operator>=(const Fixed&rhs) const;  // Plus grand ou égal (a >= b)
		bool operator<=(const Fixed&rhs) const;  // Plus petit ou égal (a <= b)
		bool operator==(const Fixed&rhs) const;  // Égal à (a == b)
		bool operator!=(const Fixed&rhs) const;  // Différent de (a != b)

		// ===== Opérateurs arithmétiques =====
		Fixed operator+(const Fixed&rhs) const;  // Addition (a + b)
		Fixed operator-(const Fixed&rhs) const;  // Soustraction (a - b)
		Fixed operator*(const Fixed&rhs) const;  // Multiplication (a * b)
		Fixed operator/(const Fixed&rhs) const;  // Division (a / b)

		// ===== Opérateurs d'incrémentation/décrémentation =====
		Fixed &operator++();    // Pré-incrémentation (++a)
		Fixed operator++(int);  // Post-incrémentation (a++)
		Fixed &operator--();    // Pré-décrémentation (--a)
		Fixed operator--(int);  // Post-décrémentation (a--)
		
		// ===== Getters & setters =====
		int		getRawBits(void) const;  // Retourne la valeur brute (format interne)
		void	setRawBits(int const raw); // Définit la valeur brute directement
		float	toFloat(void) const;       // Convertit en float
		int		toInt(void) const;         // Convertit en int (partie entière)

		// ===== Fonctions statiques min/max =====
		static	Fixed &min(Fixed &a, Fixed &b);                    // Retourne le plus petit (version modifiable)
		static const Fixed &min(const Fixed &a, const Fixed &b);   // Retourne le plus petit (version constante)
		static	Fixed &max(Fixed &a, Fixed &b);                    // Retourne le plus grand (version modifiable)
		static const Fixed &max(const Fixed &a, const Fixed &b);   // Retourne le plus grand (version constante)
} ;

// Surcharge de l'opérateur << (fonction libre)
// Permet d'utiliser std::cout << fixed_object
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif