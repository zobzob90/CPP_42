/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:13:46 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/13 16:26:09 by ertrigna         ###   ########.fr       */
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

Fixed::Fixed(float const &value)
{
	std::cout << "Float constructor called" << std::endl;
	this->stock_num = roundf(value * (1 << this->bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->stock_num = rhs.stock_num;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->stock_num);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->stock_num = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->stock_num) / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->stock_num >> this->bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}
