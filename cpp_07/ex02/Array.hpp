/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:57:49 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/10 13:31:30 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>



template <typename T>
class Array
{
	private :
		T*				_elements;
		unsigned int	_size;
	public:
		Array(); // constructeur par defaut
		Array(unsigned int n); // constructeur avec parametres;
		Array(const Array& src); // constructeur de copie pimper;
		Array& operator=(const Array& src); // Operateur d'assignation
		~Array(); // Destructeur
		
		// Operateur d'acces [] avec verif des bornes
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const ;

		unsigned int size() const;
} ;

#include "Array.tpp"

#endif