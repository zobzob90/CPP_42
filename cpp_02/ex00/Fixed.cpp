/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:49:39 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:26:16 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : stock_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	// Utilise l'opérateur d'affectation pour copier les données
    // *this fait référence à l'objet en cours de construction
    // value est l'objet source à copier
	*this = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// Vérification d'auto-affectation (éviter a = a)
    // Compare l'adresse de l'objet courant avec l'adresse de l'objet source
	if (this != &rhs)
		this->stock_num = rhs.stock_num; // Copie la valeur seulement si ce ne sont pas les mêmes objets
	return (*this); // Retourne une référence vers l'objet courant pour permettre les affectations en chaîne (a = b = c)
}

//Getter : fonction d'acces de lecture de la valeur
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->stock_num);
}

// Setter : fonction de modification de la valeur
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->stock_num = raw;
}
