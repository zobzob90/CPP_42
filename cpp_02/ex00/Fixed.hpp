/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:14:28 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					stock_num; // stocker le nombre
		static const int	bits = 8; // Nombre de bits pour la partie fractionnaire (constant pour toutes les instances)
	public:
		Fixed();
		Fixed(const Fixed &value); // Constructeur de copie (permet de créer un Fixed à partir d'un autre Fixed)
		~Fixed();
		Fixed &operator=(const Fixed &rhs); // Opérateur d'affectation (permet d'assigner un Fixed à un autre : a = b)
		int		getRawBits(void) const; // Getter : retourne la valeur brute stockée (sans conversion)
		void	setRawBits(int const raw);	// Setter : définit la valeur brute directement
} ;

#endif