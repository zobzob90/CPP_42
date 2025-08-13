/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:44 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/13 17:11:25 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					stock_num;
		static const int	bits = 8;
	public:
		//Constructeur et destructeur
		Fixed(); // Constructeur
		Fixed(const Fixed &value); 
		Fixed(int const &value); // constructeur avec l'int
		Fixed(float const &value); // constructeur avec le float
		~Fixed(); // destructeur
		
		Fixed &operator=(const Fixed &rhs); // operateur d'affectation

		//Operateur de comparaisons
		bool operator>(const Fixed&rhs) const;
		bool operator<(const Fixed&rhs) const;
		bool operator>=(const Fixed&rhs) const;
		bool operator<=(const Fixed&rhs) const;
		bool operator==(const Fixed&rhs) const;
		bool operator!=(const Fixed&rhs) const;

		//Operateur arithmetique
		Fixed operator+(const Fixed&rhs) const;
		Fixed operator-(const Fixed&rhs) const;
		Fixed operator*(const Fixed&rhs) const;
		Fixed operator/(const Fixed&rhs) const;

		//Operateur arithmetique
		Fixed &operator++(); //Pre incremente 
		Fixed operator++(int); // Post-Incremente
		Fixed &operator--(); // pre-decrement;
		Fixed operator--(int); // Post-decrement
		
		//getters & setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Surcharge de l'operateur <<
		friend std::ostream &operator<<(std::ostream &out, const Fixed &value);
} ;

#endif