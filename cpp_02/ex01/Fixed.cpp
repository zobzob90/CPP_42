/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:46 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 11:31:41 by ertrigna         ###   ########.fr       */
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
	*this = value;
}

Fixed::Fixed(int const &value)
{
	std::cout << "Int constructor called" << std::endl;
	this-> stock_num = value << this->bits;
}

// Constructeur avec float : convertit un float en virgule fixe
Fixed::Fixed(float const &value)
{
	std::cout << "Float constructor called" << std::endl;
	// Multiplie par 2^8 (256) et arrondit pour convertir en virgule fixe
	this->stock_num = roundf(value * (1 << this->bits));
}

// Destructeur : libère les ressources (ici rien à faire)
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Opérateur d'affectation : copie la valeur d'un Fixed dans un autre
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// Évite l'auto-affectation (a = a)
	if (this != &rhs)
		this->stock_num = rhs.stock_num;
	return (*this); // Retourne une référence pour les affectations en chaîne
}

// Getter : retourne la valeur brute (format virgule fixe)
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->stock_num);
}

// Setter : définit directement la valeur brute
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->stock_num = raw;
}

// Convertit la valeur virgule fixe en float
float	Fixed::toFloat(void) const
{
	// Divise par 2^8 (256) pour récupérer la valeur décimale
	return (static_cast<float>(this->stock_num) / (1 << this->bits));
}

// Convertit la valeur virgule fixe en int (partie entière)
int	Fixed::toInt(void) const
{
	// Décale de 8 bits vers la droite pour éliminer la partie fractionnaire
	return (this->stock_num >> this->bits);
}

// Opérateur de sortie : permet d'utiliser std::cout << fixed_object
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat(); // Affiche la valeur convertie en float
    return (out);
}
