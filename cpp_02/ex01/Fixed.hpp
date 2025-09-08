/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:44 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:30:13 by ertrigna         ###   ########.fr       */
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
		Fixed(); // Constructeur
		Fixed(const Fixed &value); 
		Fixed(int const &value); // constructeur avec l'int
		Fixed(float const &value); // constructeur avec le float
		~Fixed(); // destructeur
		Fixed &operator=(const Fixed &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;	
} ;

// Déclaration de l'opérateur de sortie comme fonction libre (non-membre)
// Permet d'utiliser std::cout << objet_fixed
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif